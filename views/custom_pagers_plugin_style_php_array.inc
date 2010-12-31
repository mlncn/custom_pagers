<?php
// $Id: custom_pagers_plugin_style_php_array.inc,v 1.1.2.1 2008/12/25 18:48:43 eaton Exp $

/**
 * @file
 * Handler for 'custom_pagers_php_array' style.
 */
class custom_pagers_plugin_style_php_array extends views_plugin_style {
  function render() {
    $results = array();

    // Group the rows according to the grouping field, if specified.
    $sets = $this->render_grouping($this->view->result, $this->options['grouping']);

    $base_field = $this->view->base_field;

    foreach ($sets as $title => $records) {
      foreach ($records as $label => $row) {
        $results[] = $row->{$base_field};
      }
    }
    return $results;
  }
}
