<?php
// $Id: custom_pagers_plugin_display_simple.inc,v 1.1.2.1 2008/12/25 18:48:43 eaton Exp $

/**
 * @file
 * Handler for 'custom_pagers_simple' display.
 */
class custom_pagers_plugin_display_simple extends views_plugin_display {
  function execute() {
    return $this->view->render($this->display->id);
  }

  function render() {
    return !empty($this->view->result) || !empty($this->view->style_plugin->definition['even empty']) ? $this->view->style_plugin->render($this->view->result) : '';
  }
}
