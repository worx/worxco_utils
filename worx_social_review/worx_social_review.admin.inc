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
  
  $form['worx_social_review_google_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Places Review Link'),
    '#default_value' => variable_get('worx_social_review_google_link', ''),
    '#required' => FALSE,
    '#description' => t('Please enter the link for Google Places review here.'),
  );
  $form['worx_social_review_bing_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Bing Business Portal Review Link'),
    '#default_value' => variable_get('worx_social_review_bing_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Bing's Business portal review here."),
  );
  $form['worx_social_review_yahoo_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Yahoo Listing Review Link'),
    '#default_value' => variable_get('worx_social_review_yahoo_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Yahoo's listing review here."),
  );
  $form['worx_social_review_yp_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Yellow Page's Review Link"),
    '#default_value' => variable_get('worx_social_review_yp_link', ''),
    '#required' => FALSE,
    '#description' => t('Please enter the link for Yellow Page listing review.'),
  );
  $form['worx_social_review_foursquare_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Four Square's Review Link"),
    '#default_value' => variable_get('worx_social_review_foursquare_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Four Square's review."),
  );
  $form['worx_social_review_urban_spoon_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Urban Spoon's Review Link"),
    '#default_value' => variable_get('worx_social_review_urban_spoon_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Urban Spoon's review."),
  );
  $form['worx_social_review_ta_link'] = array(
    '#type' => 'textfield',
    '#title' => t("Trip Advisor's Review Link"),
    '#default_value' => variable_get('worx_social_review_ta_link', ''),
    '#required' => FALSE,
    '#description' => t("Please enter the link for Trip Advisor's review."),
  );
  
  return system_settings_form($form);
}