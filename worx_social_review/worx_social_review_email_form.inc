<?php

/** 
 * Build the email form that customers will use to send the emails.
 */
function worx_social_review_email_form() {
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
  $form['email_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Email To Address'),
  );
  $form['tokens'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tokens'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );
  $output = array();
  $string = array();
  if (variable_get('worx_social_review_google_link', '')) {
    $string[] = '@google';
    $output['@google'] = '[google] - Google Review Link';
  }
  if (variable_get('worx_social_review_bing_link', '')) {
    $string[] = '@bing';
    $output['@bing'] = '[bing] - Bing Review Link';
  }
  if (variable_get('worx_social_review_yahoo_link', '')) {
    $string[] = '@yahoo';
    $output['@yahoo'] = '[yahoo] - Yahoo Review Link';
  }
  if (variable_get('worx_social_review_yp_link', '')) {
    $string[] = '@yp';
    $output['@yp'] = '[yp] - Yellow Pages Review Link';
  }
  if (variable_get('worx_social_review_foursquare_link', '')) {
    $string[] = '@foursquare';
    $output['@foursquare'] = '[foursquare] - Foursquare Review Link';
  }
  if (variable_get('worx_social_review_urban_spoon_link', '')) {
    $string[] = '@urbanspoon';
    $output['@urbanspoon'] = '[urbanspoon] - Urban Spoon Review Link';
  }
  if (variable_get('worx_social_review_ta_link', '')) {
    $string[] = '@ta';
    $output['@ta'] = '[ta] - Trip Advisor Review Link';
  }
  $form['tokens']['token_list'] = array(
    '#type' => 'item',
    '#markup' => '<p>' . t(implode('<br />', $string), $output ) . '</p>',
  );

  $body = variable_get('email_body', '');
  $form['email_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Email Body'),
    '#default_value' => $body['value'],
    '#format' => 'filtered_html',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
  );
  
  return $form;
}

/*
 * Define the function worx_social_review_email_form_submit.
 */
function worx_social_review_email_form_submit($form, $form_state) {
  $params['subject'] = $form_state['values']['email_subject'];
  $from = $form_state['values']['email_from'];
  $to = $form_state['values']['email_to'];
  $params['body'] = $form_state['values']['email_body']['value'];
    
  $params['google'] = variable_get('worx_social_review_google_link', '') ? variable_get('worx_social_review_google_link', '') : 'Error: No link. Please contact site administrator';
  $params['yahoo'] = variable_get('worx_social_review_yahoo_link', '') ? variable_get('worx_social_review_yahoo_link', '') : 'Error: No link. Please contact site administrator';
  $params['bing'] = variable_get('worx_social_review_bing_link', '') ? variable_get('worx_social_review_bing_link', '') : 'Error: No link. Please contact site administrator';
  $params['yp'] = variable_get('worx_social_review_yp_link', '') ? variable_get('worx_social_review_yp_link', '') : 'Error: No link. Please contact site administrator';
  $params['foursquare'] = variable_get('worx_social_review_foursquare_link', '') ? variable_get('worx_social_review_foursquare_link', '') : 'Error: No link. Please contact site administrator';
  $params['urbanspoon'] = variable_get('worx_social_review_urban_spoon_link', '') ? variable_get('worx_social_review_urban_spoon_link', '') : 'Error: No link. Please contact site administrator';
  $params['ta'] = variable_get('worx_social_review_ta_link', '') ? variable_get('worx_social_review_ta_link', '') : 'Error: No link. Please contact site administrator';
    
  drupal_mail('worx_social_review', 'social_review', $to, $language = 'UND', $params, $from);
  drupal_set_message('Email successfully sent to ' . $form_state['values']['email_to']);
}