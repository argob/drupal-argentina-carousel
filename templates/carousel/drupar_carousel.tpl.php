<div id="galeria" class="carousel slide" data-interval="false">
  
  <div class="carousel-inner" role="listbox">
      
      <div class="item active">
    
          <?php if (!is_null($video)): ?>

              <div class="embed-responsive embed-responsive-4by3">
                  <iframe class="embed-responsive-item" src="https://www.youtube.com/embed/<?= $video ?>"></iframe>
              </div>
    
          <?php else: ?>
          
              <?= array_shift ($imagenes) ?>
          
          <?php endif ?>
          
      </div>
      
      <?php foreach ($imagenes as $key => $imagen): ?>
          
          <div class="item">
            <?= $imagen ?>
          </div>
      
      <?php endforeach ?>
      
      
      <?php if($showArrows): ?>
    
          <a class="left carousel-control" style="height: 50%; margin-top: 15%; background-image: none!important;" href="#galeria" role="button" data-slide="prev">
            <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
            <span class="sr-only">Anterior</span>
          </a>
        
          <a class="right carousel-control" style="height: 50%; margin-top: 15%; background-image: none!important;" href="#galeria" role="button" data-slide="next">
            <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
            <span class="sr-only">Siguiente</span>
          </a>
      
      <?php endif ?>

</div>
