<?php

/** 
 * @file
 * worx_social_review admin panel to add review links for use in emails.
 */

/**
 * Defines the textfields to place the links in.
 * 
 * @return
 *   Fully formed Form API array.
 */
function worx_social_review_settings_form() {
  $form = array();
  
  $form['worx_socail_review_google_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Places Review Link'),
    '#default_value' => variable_get('worx_socail_review_google_link', ''),
    '#required' => FALSE,
    '#description' => t('Please enter the link for Google Places review here.'),
  );
  $form['worx_socail_review_bing_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Bing Business Portal Review Link'),
    '#default_value' => variable_get('worx_socail_review_bing_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Bing's Business portal review here."),
  );
  $form['worx_socail_review_yahoo_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Yahoo Listing Review Link'),
    '#default_value' => variable_get('worx_socail_review_yahoo_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Yahoo's listing review here."),
  );
  $form['worx_socail_review_yp_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Yellow Page's Review Link"),
    '#default_value' => variable_get('worx_socail_review_yp_link', ''),
    '#required' => FALSE,
    '#description' => t('Please enter the link for Yellow Page listing review.'),
  );
  $form['worx_socail_review_foursquare_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Four Square's Review Link"),
    '#default_value' => variable_get('worx_socail_review_foursquare_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Four Square's review."),
  );
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