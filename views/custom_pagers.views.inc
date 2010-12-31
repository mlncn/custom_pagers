<?php
// $Id: custom_pagers.views.inc,v 1.1.2.1 2008/12/25 18:48:43 eaton Exp $

/**
 * @file
 * Interface between content.module and views.module.
 */


/**
 * Implements hook_views_plugins().
 *
 * Defines some plugins used by the Views modes for
 * nodereference and userreference.
 */
function custom_pagers_views_plugins() {
  $plugins = array(
    'module' => 'custom_pagers', // This just tells our themes are elsewhere.
    'display' => array(
      'custom_pagers_simple' => array(
        'path' => drupal_get_path('module', 'custom_pagers') . '/views',
        // Those strings are not translated for now.
        // We'll need to change that if / when we remove 'no ui'
        'title' => 'Simple', // TODO: better name ? (currently not displayed anyway)
        'help' => 'Destination-agnostic display, designed for returning only a base table primary key.',
        'handler' => 'custom_pagers_plugin_display_simple',
        'no ui' => TRUE, // Programmatic use only.
        'uses hook menu' => FALSE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
      ),
    ),
    'style' => array(
      'custom_pagers_php_array' => array(
        'path' => drupal_get_path('module', 'custom_pagers') . '/views',
        // Those strings are not translated for now.
        // We'll need to change that if / when we remove 'no ui'
        'title' => 'Results array (with title)',
        'help' => 'Returns the view as a PHP array of names + rendered rows.',
        'handler' => 'custom_pagers_plugin_style_php_array',
        'no ui' => TRUE, // Programmatic use only.
        'uses row plugin' => FALSE,
        'uses fields' => FALSE,
        'type' => 'custom_pagers_simple',
        'even empty' => TRUE,
      ),
    ),
  );
  return $plugins;
}
