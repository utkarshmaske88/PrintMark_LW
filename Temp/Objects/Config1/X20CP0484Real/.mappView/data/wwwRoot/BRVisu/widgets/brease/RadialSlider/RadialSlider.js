define(['brease/core/BaseWidget',
    'brease/events/BreaseEvent',
    'widgets/brease/RadialSlider/libs/Renderer',
    'brease/datatype/Node',
    'brease/decorators/MeasurementSystemDependency', 
    'brease/core/Utils', 
    'brease/config/NumberFormat', 
    'brease/core/Types',
    'widgets/brease/common/libs/wfUtils/UtilsEditableBinding',
    'brease/decorators/DragAndDropCapability',
    'widgets/brease/common/DragDropProperties/libs/DroppablePropertiesEvents'
], function (SuperClass, BreaseEvent, Renderer, Node, 
    measurementSystemDependency, Utils, NumberFormat, 
    Types, UtilsEditableBinding, dragAndDropCapability
) {

    'use strict';

    /**
    * @class widgets.brease.RadialSlider
    * RadialSlider Widget. Input Value via slider based on Radius
    * @extends brease.core.BaseWidget
    *
    * @mixins widgets.brease.common.DragDropProperties.libs.DroppablePropertiesEvents
    * 
    * @iatMeta studio:license
    * licensed
    * @iatMeta category:Category
    * Numeric
    * @iatMeta description:short
    * Schieberegler auf Basis eines Radius
    * @iatMeta description:de
    * Ermöglicht dem Benutzer einen numerischen Wert mit einem Schiebeschalter auf Basis eines Radius zu verändern
    * @iatMeta description:en
    * Enables the user to change a numeric value by a slider based on a radius
    */

    /**
    * @cfg {Number} value=50
    * @iatStudioExposed
    * @bindable
    * @iatCategory Data
    * @nodeRefId node
    * @editableBinding
    * actual Value of the PC.  
    */

    /**
    * @cfg {Number} minValue=0
    * @iatStudioExposed
    * @iatCategory Data
    * defines the minimum Value for the value-property.  
    */

    /**
    * @cfg {Number} maxValue=100
    * @iatStudioExposed
    * @iatCategory Data
    * defines the maximum Value for the value-property.  
    */

    /**
    * @cfg {brease.datatype.Node} node=''
    * @iatStudioExposed
    * @bindable
    * @iatCategory Data
    * @editableBinding
    * Value with Unit to display on the Slider.  
    */

    /**
    * @cfg {Boolean} showValueDisplay=true
    * @iatStudioExposed
    * @iatCategory Behavior
    * Specifies if the Actual Value should be shown in the Center of the Widget.  
    */

    /**
    * @cfg {Boolean} showUnit=false
    * @iatStudioExposed
    * @iatCategory Behavior
    * Specifies wheater the unit of the displayed Value should be shown.  
    */

    /**
    * @cfg {Boolean} changeOnMove=true
    * @iatStudioExposed
    * @iatCategory Behavior
    * Specifies if the new Value should be send to the server immediatly the slider thumb is moved.  
    */

    /**
    * @cfg {UInteger} majorTicks=3
    * @iatCategory Appearance
    * Defines how many ticks are shown on the scale (Start & End Ticks are not included).  
    */

    /**
    * @cfg {brease.enum.TickStyle} tickPosition='none'
    * @iatCategory Appearance
    * Defines where the ticks should be drawn.  
    */

    /**
    * @cfg {Boolean} showTickNumbers=false
    * @iatCategory Appearance
    * Defines if the ticks show its values.  
    */

    /**
    * @cfg {brease.config.MeasurementSystemUnit} unit=''
    * @iatStudioExposed
    * @iatCategory Appearance
    * @bindable
    * Unit code depending on measurement system.  
    */

    /**
    * @cfg {brease.config.MeasurementSystemFormat} format={ 'metric': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 }, 'imperial': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 }, 'imperial-us': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 } }
    * @iatStudioExposed
    * @iatCategory Appearance
    * @bindable
    * Defines the format of the Data for each measurement system.  
    */

    /**
    * @cfg {PixelVal} trackSize=7px
    * @iatStudioExposed
    * @iatCategory Appearance
    * Defines the width of the track in which the Thumb is placed.  
    */

    /**
    * @cfg {PixelVal} thumbSize=50px
    * @iatStudioExposed
    * @iatCategory Appearance
    * Defines the diameter of the Thumb.  
    */

    /**
    * @cfg {PixelVal} radius=100px
    * @iatStudioExposed
    * @iatCategory Appearance
    * Defines the radius of the Track.  
    */

    /**
    * @cfg {UNumber} startAngle=225
    * @iatStudioExposed
    * @iatCategory Appearance
    * Defines the startAngle.  
    */

    /**
    * @cfg {UNumber} range=270
    * @iatStudioExposed
    * @iatCategory Appearance
    * Defines the range from the StartPoint to the EndPoint.  
    */

    var defaultSettings = {
            value: 50,
            minValue: 0,
            maxValue: 100,
            node: '',
            showValueDisplay: true,
            showUnit: false,
            changeOnMove: true,
            unit: null,
            format: { 'metric': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 }, 'imperial': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 }, 'imperial-us': { 'decimalPlaces': 1, 'minimumIntegerDigits': 1 } },
            trackSize: '7px',
            thumbSize: '50px',
            radius: '100px',
            startAngle: 225,
            range: 270
        },

        WidgetClass = SuperClass.extend(function RadialSlider() {
            SuperClass.apply(this, arguments);
        }, defaultSettings),

        p = WidgetClass.prototype;

    p.init = function () {

        if (this.settings.omitClass !== true) {
            this.addInitialClass('breaseRadialSlider');
        }

        this.triggerValueChangedThrottled = _.throttle(this.triggerValueChanged, 100);

        this.data = {
            node: new Node(this.settings.value, null, this.settings.minValue, this.settings.maxValue)
        };

        var rendererSettings = {
            id: this.elem.id,
            height: this.settings.height,
            width: this.settings.width,
            value: Types.parseValue(this.getValue(), 'Number', { min: this.getMinValue(), max: this.getMaxValue() }),
            minValue: this.getMinValue(),
            maxValue: this.getMaxValue(),
            radius: parseInt(this.getRadius(), 10),
            range: this.getRange(),
            showTickNumbers: this.getShowTickNumbers(),
            majorTicks: this.getMajorTicks(),
            tickPosition: this.getTickPosition(),
            showUnit: this.getShowUnit(),
            showValueDisplay: this.getShowValueDisplay(),
            format: _updateFormat(this.getFormat()),
            startAngle: this.getStartAngle(),
            thumbSize: parseInt(this.getThumbSize(), 10),
            trackSize: parseInt(this.getTrackSize(), 10),
            changeOnMove: this.getChangeOnMove(),
            unitSymbol: (brease.config.editMode) ? 'unit' : '',
            widget: this
        };

        this.renderer = new Renderer(rendererSettings);

        SuperClass.prototype.init.call(this);
        this.renderer.updatePosition();
        // prevent parent gestures when the user interacts with the thumb (e.g.: ContentCarousel)
        this.el.on('mousedown pointerdown touchstart', '.sliderThumb', this._bind(_stopEventPropagation));
        if (brease.config.editMode !== true) {
            this.addListeners();
            this.measurementSystemChangeHandler();
        }
    };  

    p._visibleHandler = function () {
        SuperClass.prototype._visibleHandler.apply(this, arguments);
        if (this.isVisible()) {
            this.renderer.redraw();
        }
    };

    /**
    * @method setValue
    * @iatStudioExposed
    * Sets value
    * @param {Number} value
    */
    p.setValue = function (value) {
        this.data.node.setValue(Types.parseValue(value, 'Number', { min: this.data.node.minValue, max: this.data.node.maxValue }));
        this.renderer.setValue(Types.parseValue(value, 'Number', { min: this.data.node.minValue, max: this.data.node.maxValue }));
    };

    /**
    * @method getValue 
    * Returns value.
    * @iatStudioExposed
    * @return {Number}
    */
    p.getValue = function () {
        return this.data.node.value;
    };

    /**
    * @method setMinValue
    * Sets minValue
    * @param {Number} minValue
    */
    p.setMinValue = function (minValue) {
        this.data.node.setMinValue(minValue);
        this.renderer.setMinValue(minValue);
    };

    /**
    * @method getMinValue 
    * Returns minValue.
    * @return {Number}
    */
    p.getMinValue = function () {
        return this.data.node.minValue;
    };

    /**
    * @method setMaxValue
    * Sets maxValue
    * @param {Number} maxValue
    */
    p.setMaxValue = function (maxValue) {
        this.data.node.setMaxValue(maxValue);
        this.renderer.setMaxValue(maxValue);
    };

    /**
    * @method getMaxValue 
    * Returns maxValue.
    * @return {Number}
    */
    p.getMaxValue = function () {
        return this.data.node.maxValue;
    };

    /**
    * @method setNode
    * Sets node
    * @param {brease.datatype.Node} node
    */
    p.setNode = function (node) {

        //Necessarry for solving following BUG: #561305
        node.minValue = parseFloat(brease.formatter.formatNumber(node.minValue, _updateFormat(this.settings.format)));
        node.maxValue = parseFloat(brease.formatter.formatNumber(node.maxValue, _updateFormat(this.settings.format)));

        this.data.node.setMinValue(node.minValue);
        this.data.node.setMaxValue(node.maxValue);
        this.data.node.setId(node.id);
        this.data.node.setValue(Types.parseValue(node.value, 'Number', { min: this.data.node.minValue, max: this.data.node.maxValue }));

        if (this.renderer.settings.minValue !== node.minValue) {
            this.renderer.setMinValue(node.minValue);
        }
        if (this.renderer.settings.maxValue !== node.maxValue) {
            this.renderer.setMaxValue(node.maxValue);
        }

        this.renderer.setValue(Types.parseValue(node.value, 'Number', { min: this.data.node.minValue, max: this.data.node.maxValue }));
    };

    /**
    * @method getNode 
    * Returns node.
    * @return {brease.datatype.Node}
    */
    p.getNode = function () {
        return this.data.node;
    };

    /**
    * @method setShowValueDisplay
    * Sets showValueDisplay
    * @param {Boolean} showValueDisplay
    */
    p.setShowValueDisplay = function (showValueDisplay) {
        this.settings.showValueDisplay = showValueDisplay;
        this.renderer.setShowValueDisplay(showValueDisplay);
    };

    /**
    * @method getShowValueDisplay 
    * Returns showValueDisplay.
    * @return {Boolean}
    */
    p.getShowValueDisplay = function () {
        return this.settings.showValueDisplay;
    };

    /**
    * @method setShowUnit
    * Sets showUnit
    * @param {Boolean} showUnit
    */
    p.setShowUnit = function (showUnit) {
        this.settings.showUnit = showUnit;
        this.renderer.setShowUnit(showUnit);
    };

    /**
    * @method getShowUnit 
    * Returns showUnit.
    * @return {Boolean}
    */
    p.getShowUnit = function () {
        return this.settings.showUnit;
    };

    /**
    * @method setChangeOnMove
    * Sets changeOnMove
    * @param {Boolean} changeOnMove
    */
    p.setChangeOnMove = function (changeOnMove) {
        this.settings.changeOnMove = changeOnMove;
    };

    /**
    * @method getChangeOnMove 
    * Returns changeOnMove.
    * @return {Boolean}
    */
    p.getChangeOnMove = function () {
        return this.settings.changeOnMove;
    };

    /**
    * @method setMajorTicks
    * Sets majorTicks
    * @param {UInteger} majorTicks
    */
    p.setMajorTicks = function (majorTicks) {
        this.settings.majorTicks = majorTicks;
        this.renderer.setMajorTicks(majorTicks);
    };

    /**
    * @method getMajorTicks 
    * Returns majorTicks.
    * @return {UInteger}
    */
    p.getMajorTicks = function () {
        return this.settings.majorTicks;
    };

    /**
    * @method setTickPosition
    * Sets tickPosition
    * @param {brease.enum.TickStyle} tickPosition
    */
    p.setTickPosition = function (tickPosition) {
        this.settings.tickPosition = tickPosition;
        this.renderer.setTickPosition(tickPosition);
    };

    /**
    * @method getTickPosition 
    * Returns tickPosition.
    * @return {brease.enum.TickStyle}
    */
    p.getTickPosition = function () {
        return this.settings.tickPosition;
    };

    /**
    * @method setShowTickNumbers
    * Sets showTickNumbers
    * @param {Boolean} showTickNumbers
    */
    p.setShowTickNumbers = function (showTickNumbers) {
        this.settings.showTickNumbers = showTickNumbers;
        this.renderer.setShowTickNumbers(showTickNumbers);
    };

    /**
    * @method getShowTickNumbers 
    * Returns showTickNumbers.
    * @return {Boolean}
    */
    p.getShowTickNumbers = function () {
        return this.settings.showTickNumbers;
    };

    /**
    * @method setUnit
    * Sets unit
    * @param {brease.config.MeasurementSystemUnit} unit
    */
    p.setUnit = function (unit) {
        this.settings.unit = unit;
        if (brease.config.editMode) {
            this.renderer.setUnitSymbol('unit');
        } else {
            this.measurementSystemChangeHandler();
        }

    };

    /**
    * @method getUnit 
    * Returns unit.
    * @return {brease.config.MeasurementSystemUnit}
    */
    p.getUnit = function () {
        return this.settings.unit;
    };

    /**
    * @method setFormat
    * Sets format
    * @param {brease.config.MeasurementSystemFormat} format
    */
    p.setFormat = function (format) {
        this.settings.format = format;
        this.renderer.setFormat(_updateFormat(format));
    };

    /**
    * @method getFormat 
    * Returns format.
    * @return {brease.config.MeasurementSystemFormat}
    */
    p.getFormat = function () {
        return this.settings.format;
    };

    /**
    * @method setTrackSize
    * Sets trackSize
    * @param {PixelVal} trackSize
    */
    p.setTrackSize = function (trackSize) {
        this.settings.trackSize = trackSize;
        this.renderer.setTrackSize(parseInt(trackSize, 10));
    };

    /**
    * @method getTrackSize 
    * Returns trackSize.
    * @return {PixelVal}
    */
    p.getTrackSize = function () {
        return this.settings.trackSize;
    };

    /**
    * @method setThumbSize
    * Sets thumbSize
    * @param {PixelVal} thumbSize
    */
    p.setThumbSize = function (thumbSize) {
        this.settings.thumbSize = thumbSize;
        this.renderer.setThumbSize(parseInt(thumbSize, 10));
    };

    /**
    * @method getThumbSize 
    * Returns thumbSize.
    * @return {PixelVal}
    */
    p.getThumbSize = function () {
        return this.settings.thumbSize;
    };

    /**
    * @method setRadius
    * Sets radius
    * @param {PixelVal} radius
    */
    p.setRadius = function (radius) {
        this.settings.radius = radius;
        this.renderer.setRadius(parseInt(radius, 10));
    };

    /**
    * @method getRadius 
    * Returns radius.
    * @return {PixelVal}
    */
    p.getRadius = function () {
        return this.settings.radius;
    };

    /**
    * @method setStartAngle
    * Sets startAngle
    * @param {UNumber} startAngle
    */
    p.setStartAngle = function (startAngle) {
        this.settings.startAngle = startAngle;
        this.renderer.setStartAngle(startAngle);
    };

    /**
    * @method getStartAngle 
    * Returns startAngle.
    * @return {UNumber}
    */
    p.getStartAngle = function () {
        return this.settings.startAngle;
    };

    /**
    * @method setRange
    * Sets range
    * @param {UNumber} range
    */
    p.setRange = function (range) {
        this.settings.range = range;
        this.renderer.setRange(range);
    };

    /**
    * @method getRange 
    * Returns range.
    * @return {UNumber}
    */
    p.getRange = function () {
        return this.settings.range;
    };

    /**
    * @method submitChange
    * Send value to the server, if binding for this widget exists.  
    * Usage of this method will only make sense, if submitOnChange=false, as otherwise changes are submitted automatically.
    */
    p.submitChange = function () {
        this.sendValueChange({ value: this.getValue(), node: this.getNode() });

        this.triggerValueChangedThrottled();
    };

    p.triggerValueChanged = function () {
        /**
        * @event ValueChanged
        * @iatStudioExposed
        * Fired when index changes.
        * @param {Number} value
        */
        var ev = this.createEvent('ValueChanged', { value: this.getValue() });
        ev.dispatch();
    };

    p.suspend = function () {
        this.removeListeners();
        SuperClass.prototype.suspend.apply(this, arguments);
    };

    p.wake = function () {
        this.addListeners();
        SuperClass.prototype.wake.apply(this, arguments);
    };

    p.dispose = function () {
        this.removeListeners();
        this.triggerValueChangedThrottled.cancel();
        SuperClass.prototype.dispose.apply(this, arguments);
    };

    p.addClassNames = function (classNames) {
        var widget = this;
        classNames.forEach(function (id) {
            widget.el.addClass(id);
        });
        this.initialized = true;
    };

    p.setEditable = function (editable, metaData) {
        UtilsEditableBinding.handleEditable(editable, metaData, this, ['value', 'node']);
    };

    p.enable = function () {
        SuperClass.prototype.enable.call(this);
        this.classHandling();
    };

    p.disable = function () {
        SuperClass.prototype.disable.call(this);
        this.classHandling();
    };

    p.classHandling = function () {
        if (this.isDisabled) {
            $(this.renderer.arcGroupPath[0][0]).addClass('disabled');
            $(this.renderer.arcGroupFillPath[0][0]).addClass('disabled');
            $(this.renderer.thumb[0][0]).addClass('disabled');
        } else {
            $(this.renderer.arcGroupPath[0][0]).removeClass('disabled');
            $(this.renderer.arcGroupFillPath[0][0]).removeClass('disabled');
            $(this.renderer.thumb[0][0]).removeClass('disabled');
        }
    };

    p.measurementSystemChangeHandler = function () {
        var widget = this;
        this.settings.mms = brease.measurementSystem.getCurrentMeasurementSystem();
        this.valueChange = $.Deferred();
        this.unitChange = $.Deferred();

        $.when(this.valueChange.promise(), this.unitChange.promise()).then(function successHandler() {
            widget.renderer.setFormat(_updateFormat(widget.settings.format));
        });

        var previousUnitCode = this.data.node.unit;
        if (this.settings.unit !== null) {
            this.data.node.setUnit(this.settings.unit[this.settings.mms]);
        }

        if (this.data.node.unit !== previousUnitCode) {
            brease.language.pipeAsyncUnitSymbol(this.data.node.unit, this._bind(_setUnitSymbol));
        } else {
            this.unitChange.resolve();
        }

        var subscriptions = brease.uiController.getSubscriptionsForElement(this.elem.id);
        if (subscriptions !== undefined && subscriptions.node !== undefined) {
            if (this.data.node.unit !== previousUnitCode) {
                this.sendNodeChange({ attribute: 'node', nodeAttribute: 'unit', value: this.data.node.unit });
            }
        }
        this.valueChange.resolve();
    };

    p.themeChange = function () {
        if (this.isVisible() && this.renderer !== undefined) {
            this.renderer.redraw();
        }
    };

    function reDrawListener(e) {
        if (e.detail.contentId === this.getParentContentId()) {
            this.renderer.redraw();
        }
    }

    p.addListeners = function () {
        if (isNaN(this.settings.height) || isNaN(this.settings.width)) {
            brease.bodyEl.on(BreaseEvent.FRAGMENT_SHOW, this._bind(reDrawListener));
        }
        brease.bodyEl.on(BreaseEvent.THEME_CHANGED, this._bind('themeChange'));
    };

    p.removeListeners = function () {
        brease.bodyEl.off(BreaseEvent.THEME_CHANGED, this._bind('themeChange'));
        brease.bodyEl.off(BreaseEvent.FRAGMENT_SHOW, this._bind(reDrawListener));
    };

    //ACTIONS
    
    /**
    * @method setStyle
    * Sets a predefined style for the widget
    * @iatStudioExposed
    * @param {StyleReference} value
    */
    p.setStyle = function () {
        SuperClass.prototype.setStyle.apply(this, arguments);
        if (this.renderer !== undefined) {
            this.renderer.updatePosition();
        }
    };

    //EVENTS

    /**
    * @event MouseDown
    * @iatStudioExposed
    * Fired when widget enters mouseDown state
    * @param {String} horizontalPos horizontal position of mouse in pixel i.e '10px'
    * @param {String} verticalPos vertical position of mouse in pixel i.e '10px'
    */

    p._mouseDownHandler = function (e) {
        if (this.isDisabled) { return; }
        var clickEv = this.createMouseEvent('MouseDown', {}, e);
        clickEv.dispatch();
    };

    /**
    * @event MouseUp
    * @iatStudioExposed
    * Fired when widget enters mouseUp state
    * @param {String} horizontalPos horizontal position of mouse in pixel i.e '10px'
    * @param {String} verticalPos vertical position of mouse in pixel i.e '10px'
    */

    p._mouseUpHandler = function (e) {
        if (this.isDisabled) { return; }
        var clickEv = this.createMouseEvent('MouseUp', {}, e);
        clickEv.dispatch();
    };

    // override method called in BaseWidget.init
    p._initEditor = function () {
        var widget = this;
        require(['widgets/brease/common/libs/EditorHandlesSquare'], function (EditorHandles) {
            var editorHandles = new EditorHandles(widget);
            widget.getHandles = function () {
                return editorHandles.getHandles();
            };
            widget.designer.getSelectionDecoratables = function () {
                return editorHandles.getSelectionDecoratables();
            };
            widget.designer.isSquare = function () {
                return true;
            };
        });
    
        this.elem.addEventListener(BreaseEvent.WIDGET_STYLE_PROPERTIES_CHANGED, this._bind('_editorStyleChanged'));
    };

    p._editorStyleChanged = function () {
        if (this.renderer) {
            this.renderer.redraw();
        }
    };

    p._redrawInEditor = function (height, width) {
        if (height !== undefined) { this._setHeight(height); }
        if (width !== undefined) { this._setWidth(width); }
        if (this.renderer) {
            this.renderer.redraw();
        }
    };

    //PRIVATE FUNCTIONS:

    function _setUnitSymbol(symbol) {
        this.settings.unitSymbol = symbol;
        this.renderer.setUnitSymbol(symbol);
        this.unitChange.resolve();
    }

    function _updateFormat(format) {
        if (format !== undefined) {
            if (Utils.isObject(format)) {
                return NumberFormat.getFormat(format, brease.measurementSystem.getCurrentMeasurementSystem());
            }
        }
    }

    function _stopEventPropagation(e) {
        if (!brease.config.editMode && this.isEnabled()) {
            e.stopPropagation();
        }
    }
    return dragAndDropCapability.decorate(measurementSystemDependency.decorate(WidgetClass, true), false);

});
