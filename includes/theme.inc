<?php

/**
 * Returns HTML for status and/or error messages, grouped by type.
 */
function theme_bootstrap_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  $class = array(
    'status' => 'alert-info',
    'error' => 'alert-error',
    'warning' => 'alert-heading',
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"alert alert-block " . $class[$type] . "\">\n";
    $output .= "<a class=\"close\">x</a>\n";
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Returns HTML for a breadcrumb trail.
 */
function theme_bootstrap_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<ul class="breadcrumb"><li>' . implode(' <span class="divider">/</span></li><li>', $breadcrumb) . '</li></ul>';
    return $output;
  }
}

