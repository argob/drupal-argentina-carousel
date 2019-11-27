
<?php

$plugin = [
    
    'single' => TRUE,
    'title' => t('Carousel'),
    'description' => t('Muestra un listado de imágenes y videos al estilo carousel'),
    'category' => t('Drupar'),
    'render callback' => 'drupar_carousel_render',
    'admin info' => 'drupar_carousel_admin_info',
    'defaults' => array(),
    
];

/**
 * 'admin info' callback for panel pane.
 */
function drupar_carousel_admin_info($subtype, $conf, $contexts)
{
    if (!empty($conf)) {
        
        $block = new stdClass;
        $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Carousel de imágenes');
        $block->content = t('Modulo Carousel');
        
        return $block;
    }
}


function drupar_carousel_render($subtype, $conf, $panel_args, $context = NULL)
{
    
    $block = new stdClass();
    $block->title = '';
    
    $node_wrapper = entity_metadata_wrapper('node', arg(1));
    
    try {
        
        if (empty(($imagenes = $node_wrapper->field_imagenes->value())) && !($video = $node_wrapper->field_video->value())) {
            // Casteo stdClass a un Array por compatibilidad
            $imagenes = [(array)file_load(147005)];
        }
        
        $block->content = theme(
            'drupar_carousel',
            [
                'imagenes' => getCarouselImages($imagenes),
                'video' => $node_wrapper->field_video->value(),
                'showArrows' => ($video && !empty($imagenes)) || (!$video && sizeof($imagenes) > 1)
            ]
        );
        
    } catch (Exception $e) {
        
        $block->content = null;
        
    }
    
    return $block;
    
}

function getCarouselImages($files)
{
    $images = [];
    
    foreach ($files as $image) {
        
        $images[] = theme_image([

            'path' => file_create_url($image['uri']),
            'alt' => $image['alt'],
            'title' => $image['title'],
            'width' => 750,
            'height' => 562,
            'attributes' => [
                'typeof' => 'foaf:Image',
                'class' => [
                    'img-responsive'
                ]
            ]

        ]);

    }
    
    return $images;
}