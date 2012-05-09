<?php

/**
 * Defines the template for customers to set default email values.
 * 
 * @return
 *   Fully formed Form API array.
 */

function worx_social_review_email_template_form() {
  $form = array();

  $form['email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Subject'),
    '#default_value' => variable_get('email_subject', ''),
  );
  $form['email_from'] = array(
    '#type' => 'textfield',
    '#title' => t('Email From Address'),
    '#default_value' => variable_get('email_from', ''),
  );
  $body = variable_get('email_body', '');
  $form['email_body']['email_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Email Body'),
    '#default_value' => $body['value'],
    '#format' => 'filtered_html',
  );
  return system_settings_form($form);
}