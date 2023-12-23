define([
    'brease/core/Class',
    'libs/d3/d3',
    'widgets/brease/common/libs/redux/utils/UtilsSize',
    'brease/core/Utils'
], function (SuperClass, d3, UtilsSize, Utils) {
    'use strict';

    var renderer = SuperClass.extend(function renderer(settings) {
            SuperClass.call(this);
            this.settings = settings;
            this.widget = settings.widget;     
            this.initialize();
        }, null),

        p = renderer.prototype;

    p.initialize = function () {
        if (this.settings.startAngle === 0) {
            this.settings.startAngle = 0.1;
        }
        this.settings.endAngle = _calculateEndAngle(this.settings.startAngle, this.settings.range);
        this._setSize();
        this.startQuadrant = this.getAngleQuadrant(this.settings.startAngle);
        _createDragBehavior(this);
        _createScale(this);
        _appendGroup(this);        
        _writeValue(this);
    };

    p.dragStart = function (d) {
        if ((brease.config.editMode === true) || (this.widget.isDisabled)) {
            return;
        }

        this.widget._mouseDownHandler(d);

        d3.event.sourceEvent.preventDefault();
        d3.event.sourceEvent.stopPropagation();
    };

    p.dragMove = function () {
        if ((brease.config.editMode === true) || (this.widget.isDisabled)) {
            return;
        }
        this.degree = Utils.radToDeg(Math.atan(d3.event.y / d3.event.x));

        _calculateAngle(this);
        _calculateValue(this);

        if (this.settings.changeOnMove === true) {
            this.widget.submitChange();
        }
    };

    p.dragEnd = function (d) {
        if ((brease.config.editMode === true) || (this.widget.isDisabled)) {
            return;
        }
        this.widget.submitChange();
        this.widget._mouseUpHandler(d);
    };

    p.setValue = function (value) {
        this.settings.value = value;
        _moveThumb(this);
        _moveFillArc(this);
        _writeValue(this);
    };

    p.setMinValue = function (minValue) {
        this.settings.minValue = minValue;
        _updateScale(this);
        this.redraw();
    };
   
    p.setMaxValue = function (maxValue) {
        this.settings.maxValue = maxValue;
        _updateScale(this);
        this.redraw();
    };

    p._setSize = function () {
        if (this.widget.settings !== undefined) { this.settings.width = this.widget.settings.width; }
        if (this.widget.settings !== undefined) { this.settings.height = this.widget.settings.height; }

        this.widgetWidth = UtilsSize.getWidth(this.settings.width, this.widget.elem);
        this.widgetHeight = UtilsSize.getHeight(this.settings.height, this.widget.elem);
    };

    p.setShowValueDisplay = function (showValueDisplay) {
        this.settings.showValueDisplay = showValueDisplay;
        this.valueDisplayHandling();
    };

    p.setShowUnit = function (showUnit) {
        this.settings.showUnit = showUnit;
        _writeValue(this);
    };  

    p.setShowTickNumbers = function (showTickNumbers) {
        this.settings.showTickNumbers = showTickNumbers;
    };

    p.setMajorTicks = function (majorTicks) {
        this.settings.majorTicks = majorTicks;
    };

    p.setTickPosition = function (tickPosition) {
        this.settings.tickPosition = tickPosition;
    };

    p.setTrackSize = function (trackSize) {
        this.settings.trackSize = trackSize;
        this.redraw();
    };

    p.setThumbSize = function (thumbSize) {
        this.settings.thumbSize = thumbSize;
        this.redraw();
    };

    p.setRadius = function (radius) {
        this.settings.radius = radius;
        this.redraw();
    };

    p.setStartAngle = function (startAngle) {
        this.settings.startAngle = startAngle;
        this.settings.endAngle = _calculateEndAngle(this.settings.startAngle, this.settings.range);
        this.redraw();
    };

    p.setRange = function (range) {
        this.settings.range = range;
        this.settings.endAngle = _calculateEndAngle(this.settings.startAngle, this.settings.range);
        this.redraw();
    };

    p.setFormat = function (format) {
        this.settings.format = format;
        _writeValue(this);
    };

    p.setUnitSymbol = function (symbol) {
        this.settings.unitSymbol = symbol;
        _writeValue(this);
    };

    p.redraw = function () {        
        this.groups.remove();
        this._setSize();
        _appendGroup(this);
        _writeValue(this);
        this.widget.classHandling();
    };

    p.valueDisplayHandling = function () {
        if (this.settings.showValueDisplay) {
            this.output.attr('display', '');
        } else {
            this.output.attr('display', 'none');
        }
    };

    function _createDragBehavior(renderer) {
        renderer.dragBehavior = d3.behavior.drag()
            .origin(function (d) { return d; })
            .on('dragstart', renderer._bind(renderer.dragStart))
            .on('drag', renderer._bind(renderer.dragMove))
            .on('dragend', renderer._bind(renderer.dragEnd));
    }

    function _appendGroup(renderer) {
        renderer.sliderContainer = d3.select('#' + renderer.settings.id);

        renderer.groups = renderer.sliderContainer.append('g')
            .attr('class', 'RadialSliderGroup');

        renderer.updatePosition();

        _valueDisplayDraw(renderer);
        _appendArcs(renderer);
        _appendThumb(renderer);

    }

    p.updatePosition = function () {
        var el = $('#' + this.settings.id);

        this.border = {
            left: parseInt(el.css('border-left-width'), 10),
            top: parseInt(el.css('border-top-width'), 10),
            right: parseInt(el.css('border-right-width'), 10),
            bottom: parseInt(el.css('border-bottom-width'), 10)
        };

        var center = this.calculatePosition(this.widgetHeight, this.widgetWidth, this.border);

        this.groups.attr('transform', 'translate(' + center.x + ',' + center.y + ')');
    };

    p.calculatePosition = function (height, width, border) {
        return {
            x: ((width - border.left - border.right) / 2),
            y: ((height - border.top - border.bottom) / 2)
        };
    };

    function _appendArcs(renderer) {
        renderer.arcGroup = renderer.groups.append('g')
            .attr('class', 'arc');

        renderer.arc = d3.svg.arc()
            .innerRadius((renderer.settings.radius - renderer.settings.trackSize))
            .outerRadius(renderer.settings.radius)
            .startAngle(Utils.degToRad(renderer.settings.startAngle))
            .endAngle(Utils.degToRad(renderer.settings.endAngle));

        renderer.arcGroupPath = renderer.arcGroup.append('path')
            .attr('class', 'arcPath')
            .attr('d', renderer.arc);

        renderer.arcGroupFill = renderer.groups.append('g')
            .attr('class', 'arcFill');

        renderer.arcFill = d3.svg.arc()
            .innerRadius((renderer.settings.radius - renderer.settings.trackSize))
            .outerRadius(renderer.settings.radius)
            .startAngle(Utils.degToRad(renderer.settings.startAngle))
            .endAngle(Utils.degToRad(renderer.settings.startAngle));

        renderer.arcGroupFillPath = renderer.arcGroupFill.append('path')
            .attr('class', 'arcFillPath')
            .attr('d', renderer.arcFill);

        _moveFillArc(renderer);
    }

    function _appendThumb(renderer) {
        renderer.thumbGroup = renderer.groups.append('g')
            .attr('class', 'thumb');

        renderer.thumb = renderer.thumbGroup.append('circle')
            .data([_calculateThumbPosition(renderer)])
            .attr('class', 'sliderThumb')
            .attr('r', renderer.settings.thumbSize / 2)
            .attr('cx', function (d) { return d.x; })
            .attr('cy', function (d) { return d.y; })
            .call(renderer.dragBehavior);
    }

    function _createScale(renderer) {
        renderer.scale = d3.scale.linear()
            .domain([0, renderer.settings.range])
            .range([renderer.settings.minValue, renderer.settings.maxValue]);
    }

    function _calculateEndAngle(startAngle, range) {
        return startAngle + range;
    }

    p.getAngleQuadrant = function (angle) {
        if (angle >= 0 && angle <= 90) {
            return 1;
        } else if (angle > 90 && angle <= 180) {
            return 2;
        } else if (angle > 180 && angle <= 270) {
            return 3;
        } else if (angle > 270 && angle < 360) {
            return 4;
        }
    };

    p.getEventQuadrant = function (d3Event) {
        if (d3Event.x > 0 && d3Event.y < 0) {
            return 1;
        } else if (d3Event.x > 0 && d3Event.y > 0) {
            return 2;
        } else if (d3Event.x < 0 && d3Event.y > 0) {
            return 3;
        } else if (d3Event.x < 0 && d3Event.y < 0) { 
            return 4;
        }
    };

    function _calculateAngle(renderer) {
        var evtqu = renderer.getEventQuadrant(d3.event),
            degree = Math.abs(renderer.degree),
            startAngle = renderer.settings.startAngle;

        switch (renderer.startQuadrant) {

            case 1: //startAngle in quadrant 1
                
                switch (evtqu) {
                    case 1:
                        renderer.angle = 90 - degree - startAngle;
                        break;
                    case 2:
                        renderer.angle = 90 + degree - startAngle;
                        break;
                    case 3:
                        renderer.angle = 270 - degree - startAngle;
                        break;
                    case 4:
                        renderer.angle = 270 + degree - startAngle;
                        break;
                }
                break;

            case 2: //startAngle in quadrant 2
                switch (evtqu) {
                    case 1:
                        renderer.angle = 360 - degree - (startAngle - 90);
                        break;
                    case 2:
                        renderer.angle = degree - (startAngle - 90);
                        break;
                    case 3:
                        renderer.angle = 180 - degree - (startAngle - 90);
                        break;
                    case 4:
                        renderer.angle = 180 + degree - (startAngle - 90);
                        break;
                }
                break;

            case 3: //startAngle in quadrant 3
                switch (evtqu) {
                    case 1:
                        renderer.angle = 270 - degree - (startAngle - 180);
                        break;
                    case 2:
                        renderer.angle = 270 + degree - (startAngle - 180);
                        break;
                    case 3:
                        renderer.angle = 90 - degree - (startAngle - 180);
                        break;
                    case 4:
                        renderer.angle = 90 + degree - (startAngle - 180);
                        break;
                }
                break;

            case 4: //startAngle in quadrant 4
                switch (evtqu) {
                    case 1:
                        renderer.angle = 180 - degree - (startAngle - 270);
                        break;
                    case 2:
                        renderer.angle = 180 + degree - (startAngle - 270);
                        break;
                    case 3:
                        renderer.angle = 360 - degree - (startAngle - 270);
                        break;
                    case 4:
                        renderer.angle = degree - (startAngle - 270);
                        break;
                }
                break;

        }
        if (renderer.angle < 0) {
            renderer.angle = renderer.angle + 360;
        }
    }

    function _calculateValue(renderer) {

        var value = parseFloat(brease.formatter.formatNumber(renderer.scale(renderer.angle), renderer.settings.format)),
            oldValue = renderer.settings.widget.getValue();

        if (value < renderer.settings.minValue || value > renderer.settings.maxValue) {
            var averageValue = (renderer.settings.minValue + renderer.settings.maxValue) / 2;
            if ((oldValue < averageValue)) {
                renderer.settings.widget.setValue(renderer.settings.minValue);
            } else {
                renderer.settings.widget.setValue(renderer.settings.maxValue);
            }
        } else {
            renderer.settings.widget.setValue(value);
        }

    }
    
    function _calculateThumbPosition(renderer) {
        var angle, obj = {};
        if (renderer.settings.minValue !== renderer.settings.maxValue) {
            angle = ((renderer.settings.startAngle + ((renderer.settings.value - renderer.settings.minValue) / (renderer.settings.maxValue - renderer.settings.minValue) * renderer.settings.range)) % 360) - 90;
        } else {
            angle = renderer.settings.startAngle - 90;
        }

        obj = {
            x: ((renderer.settings.radius) - (renderer.settings.trackSize / 2)) * Math.cos(Utils.degToRad(angle)),
            y: ((renderer.settings.radius) - (renderer.settings.trackSize / 2)) * Math.sin(Utils.degToRad(angle))
        };
        return obj;
    }

    function _moveThumb(renderer) {
        renderer.thumb.data([_calculateThumbPosition(renderer)])
            .attr('cx', function (d) { return d.x; })
            .attr('cy', function (d) { return d.y; });
    }

    function _moveFillArc(renderer) {
        var angle;
        if (renderer.settings.minValue !== renderer.settings.maxValue) {
            angle = ((renderer.settings.startAngle + ((renderer.settings.value - renderer.settings.minValue) / (renderer.settings.maxValue - renderer.settings.minValue) * renderer.settings.range)) % 360);
        } else {
            angle = renderer.settings.startAngle;
        }
        
        if (angle < renderer.settings.startAngle) {
            angle = 360 + angle;
        }
        var endangle = Utils.degToRad(angle);

        renderer.arcFill.endAngle(endangle);
        renderer.arcGroupFillPath.attr('d', renderer.arcFill);
    }

    function _valueDisplayDraw(renderer) {        
               
        renderer.output = renderer.groups.append('g')
            .attr('class', 'valueDisplay');

        renderer.outputVal = renderer.output.append('text')
            .attr('class', 'valueOutput')                                            
            .attr('text-anchor', 'middle')
            .attr('alignment-baseline', 'middle');
        renderer.valueDisplayHandling();
    }

    function _writeValue(renderer) {
        var value = brease.formatter.formatNumber(renderer.settings.value, renderer.settings.format);

        if (renderer.settings.unitSymbol !== undefined && renderer.settings.showUnit === true) {
            renderer.outputVal.text(value + ' ' + renderer.settings.unitSymbol);
        } else {
            renderer.outputVal.text(value);
        }         
    }

    function _updateScale(renderer) {
        renderer.scale.range([renderer.settings.minValue, renderer.settings.maxValue]);
    }

    return renderer;
});
