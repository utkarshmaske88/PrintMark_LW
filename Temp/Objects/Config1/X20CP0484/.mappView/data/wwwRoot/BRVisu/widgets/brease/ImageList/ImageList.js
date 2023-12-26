define([
    'brease/core/BaseWidget', 
    'brease/events/BreaseEvent',
    'widgets/brease/ImageList/libs/config/Config',
    'widgets/brease/common/libs/flux/stores/ImageStore/ImageStore',
    'widgets/brease/common/libs/flux/stores/ImageStore/ImageActions',
    'widgets/brease/common/libs/flux/views/ImageView/ImageView',
    'brease/decorators/DragAndDropCapability',
    'widgets/brease/common/libs/BreaseResizeObserver',
    'brease/decorators/ContentActivatedDependency',
    'widgets/brease/common/DragDropProperties/libs/DraggablePropertiesEvents',
    'widgets/brease/common/DragDropProperties/libs/DroppablePropertiesEvents'
], function (SuperClass, BreaseEvent, Config, ImageStore, ImageActions, ImageView, dragAndDropCapability, BreaseResizeObserver, ContentActivatedDependency) {

    'use strict';

    /**
     * @class widgets.brease.ImageList
     * #Description
     * Widget for displaying an image
     * @breaseNote 
     * @extends brease.core.BaseWidget
     *
     * @mixins widgets.brease.common.DragDropProperties.libs.DraggablePropertiesEvents
     * @mixins widgets.brease.common.DragDropProperties.libs.DroppablePropertiesEvents
     * 
     * @iatMeta category:Category
     * Image
     * @iatMeta description:short
     * Grafikobjekt
     * @iatMeta description:de
     * Ermöglicht die Anzeige eines selektierten Image aus einer Liste von Images
     * @iatMeta description:en
     * Allows to display a selected image from a list of images
     */

    var defaultSettings = Config,

        WidgetClass = SuperClass.extend(function ImageList() {
            SuperClass.apply(this, arguments);
        }, defaultSettings),

        p = WidgetClass.prototype;

    p.registerStore = function registerStore(store) {
        this.registeredStores.push(store);
    };

    p.dispatch = function dispatch(action) {
        this.registeredStores.forEach(function (store) {
            store.newAction(action);
        });
    };

    p.init = function () {

        //1. Add initial classes
        if (this.settings.omitClass !== true) {
            this.addInitialClass('breaseImageList');
        }

        //2. Define empty store register
        this.registeredStores = [];

        //3. Initialize superclass
        this.observer = new BreaseResizeObserver(this.elem, this._bind(_updateSize));
        SuperClass.prototype.init.call(this);

        //4. Define init state
        var initImageState = {
            imageList: this.settings.imageList,
            imageIndex: this.settings.selectedIndex,
            pathPrefix: this.settings.imagePrefix,
            sizeMode: this.settings.sizeMode,
            useSVGStyling: this.settings.useSVGStyling,
            backgroundAlignment: this.settings.imageAlign,
            height: '100%',
            width: '100%',
            visible: this.isVisible(),
            preloading: brease.config.preLoadingState
        };

        //5. Define stores and actions
        this.imageStore = new ImageStore(this, initImageState);
        this.imageActions = new ImageActions(this);

        //6. Define views
        this.imageView = new ImageView(this.imageStore, this, this.el);

        //7. Trigger init store action
        this.imageActions.initImage();
        this.addListeners();
    };

    // override method called in BaseWidget.init
    p._initEditor = function () {
        var widget = this;
        widget.el.addClass('iatd-outline');
        require(['widgets/brease/ImageList/libs/EditorHandles'], function (EditorHandles) {
            var editorHandles = new EditorHandles(widget);
            widget.getHandles = function () {
                return editorHandles.getHandles();
            };
            widget.designer.getSelectionDecoratables = function () {
                return editorHandles.getSelectionDecoratables();
            };
            widget.dispatchEvent(new CustomEvent(BreaseEvent.WIDGET_EDITOR_IF_READY, { bubbles: true }));
            widget.observer.init();
        });
    };

    p._setWidth = function (w) {
        SuperClass.prototype._setWidth.apply(this, arguments);
        this.imageActions.setWidth('100%');
    };

    p._setHeight = function (h) {
        SuperClass.prototype._setHeight.apply(this, arguments);
        this.imageActions.setHeight('100%');
    };

    p.updateSize = function () {
        this.imageActions.setWidth('100%');
        this.imageActions.setHeight('100%');
    };

    /**
     * @method setImageList
     * Sets imageList
     * @param {GraphicCollection} imageList
     */
    p.setImageList = function (imageList) {
        this.settings.imageList = imageList;
        this.imageActions.setImageList(imageList);
    };

    /**
     * @method getImageList 
     * Returns imageList
     * @return {GraphicCollection}
     */
    p.getImageList = function () {
        return this.settings.imageList;
    };

    /**
     * @method setSizeMode
     * Sets sizeMode
     * @param {brease.enum.SizeMode} sizeMode
     */
    p.setSizeMode = function (sizeMode) {
        this.settings.sizeMode = sizeMode;
        this.imageActions.setSizeMode(sizeMode);
    };

    /**
     * @method getSizeMode 
     * Returns sizeMode.
     * @return {brease.enum.SizeMode}
     */
    p.getSizeMode = function () {
        return this.imageStore.getImageSizeMode();
    };

    /**
     * @method setImagePrefix
     * Sets imagePrefix
     * @param {DirectoryPath} imagePrefix
     */
    p.setImagePrefix = function (imagePrefix) {
        this.settings.imagePrefix = imagePrefix;
        this.imageActions.setPathPrefix(imagePrefix);
    };

    /**
     * @method getImagePrefix 
     * Returns imagePrefix
     * @return {DirectoryPath}
     */
    p.getImagePrefix = function () {
        return this.settings.imagePrefix;
    };

    /**
     * @method setImageAlign
     * Sets imageAlign       
     * @param {brease.enum.BackgroundPosition} imageAlign
     */
    p.setImageAlign = function (imageAlign) {
        this.settings.imageAlign = imageAlign;
        this.imageActions.setBackgroundAlignment(imageAlign);
    };

    /**
     * @method getImageAlign 
     * Returns imageAlign
     * @return {brease.enum.BackgroundPosition}
     */
    p.getImageAlign = function () {
        return this.settings.imageAlign;
    };

    /**
     * @method setSelectedIndex
     * @iatStudioExposed
     * Sets the index for the image list
     * @param {Integer} index
     */
    p.setSelectedIndex = function (index) {
        var numericSelectedIndex = Number(index);
        this.settings.selectedIndex = numericSelectedIndex;
        this.imageActions.setImageIndex(numericSelectedIndex);
        /**
         * @event SelectedIndexChanged
         * @iatStudioExposed
         * Fired when index changes
         * @param {Integer} selectedIndex
         */
        var ev = this.createEvent('SelectedIndexChanged', { selectedIndex: numericSelectedIndex });
        ev.dispatch();
    };

    /**
     * @method getSelectedIndex
     * gets the index for the image list
     * @return {Integer} index
     */
    p.getSelectedIndex = function () {
        return this.settings.selectedIndex;
    };

    /**
     * @method setUseSVGStyling
     * Sets useSVGStyling
     * @param {Boolean} useSVGStyling
     */
    p.setUseSVGStyling = function (useSVGStyling) {
        this.settings.useSVGStyling = useSVGStyling;
        this.imageActions.setUseSVGStyling(useSVGStyling);
    };

    /**
     * @method getUseSVGStyling
     * Returns useSVGStyling
     * @return {Boolean}
     */
    p.getUseSVGStyling = function () {
        return this.imageStore.getUseSVGStyling();
    };

    p._visibleHandler = function () {
        SuperClass.prototype._visibleHandler.apply(this, arguments);
        if (this.imageActions !== undefined) {
            this.imageActions.setVisible(this.isVisible());
        }
        _updateSize.call(this);
    };
    p.addListeners = function () {
        document.body.addEventListener(BreaseEvent.THEME_CHANGED, this._bind(_updateSize));
    };

    p.removeListeners = function () {
        document.body.removeEventListener(BreaseEvent.THEME_CHANGED, this._bind(_updateSize));
    };
    p.suspend = function () {
        this.removeListeners();
        this.observer.suspend();
        SuperClass.prototype.suspend.apply(this, arguments);
    };
    p.wake = function () {
        if (this.internalData.preLoaded) {
            this.imageActions.initImageAfterPreload();
            this.internalData.preLoaded = false;
        }        
        this.addListeners();
        SuperClass.prototype.wake.apply(this, arguments);
    };
    p.dispose = function () {
        this.removeListeners();
        this.observer.dispose();
        this.observer = undefined;
        SuperClass.prototype.dispose.apply(this, arguments);
    };
    p.contentActivatedHandler = function () {
        if (this.observer.initialized) {
            this.observer.wake();
        } else {
            this.observer.init();
        }
    };
    function _updateSize() {
        if (this.isVisible() && this.imageActions) {
            this.updateSize();
        }
    }
    return ContentActivatedDependency.decorate(dragAndDropCapability.decorate(WidgetClass, false), true);

});
