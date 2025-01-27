<?php

  /**
 * Settings form for Revision Helper.
 */
function revision_helper_settings($form, &$form_state) {

  $form = array();

  // Get existing configuration.
  $config = config_get('revision_helper.settings');

  // Add a color picker.
  $form['revision_color'] = array(
    '#type' => 'color',
    '#title' => t('Revision Background Color'),
    '#default_value' => isset($config['revision_color']) ? $config['revision_color'] : '#ff0000',
    '#description' => t('Choose a color to highlight content marked as a revision.'),
  );

  $form['revision_status_message'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show status message for revisions'),
    '#default_value' => isset($config['revision_status_message']) ? $config['revision_status_message'] : TRUE,
    '#description' => t('Enable or disable the display of a status message when viewing a revision.'),
  );

  // Submit button.
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#submit' => array('revision_helper_settings_form_submit'),
  );

  return $form;
}

/**
 * Submit handler for the settings form.
 */
function revision_helper_settings_form_submit($form, &$form_state) {
  // Save the selected color to configuration.
  config_set('revision_helper.settings', 'revision_color', $form_state['values']['revision_color']);
  config_set('revision_helper.settings', 'revision_status_message', $form_state['values']['revision_status_message']);
  backdrop_set_message(t('The configuration has been saved.'), 'status');
}
