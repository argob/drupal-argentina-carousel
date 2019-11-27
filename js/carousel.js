(function($) {
  $(document).ready( function() {
    $('.carousel .item img').removeClass('img-responsive').addClass('img-full');
    $( '.carousel-control' ).css( "top", "10%" ).css( "height", "80%" );
    $( '.carousel-control.right, .carousel-control.left' ).css( "background-image", "none" );
  })
})(jQuery);