<?php

function drupar_carousel_theme($existing, $type, $theme, $path){
  return array(
    'drupar_carousel' => array(
      'path' => drupal_get_path('module', 'drupar_carousel') . '/templates/carousel',
      'template' => 'drupar_carousel',
    ),
  );
}
