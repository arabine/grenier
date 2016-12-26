<SCRIPT LANGUAGE="JavaScript">

function AfficherImage(img)
{
  Image1= new Image();
  Image1.src=(img);
  if((Image1.width!=0)&&(Image1.height!=0))
  {
    largeur=Image1.width+20;
    hauteur=Image1.height+20;
    proprietes="width="+ largeur +",height="+ hauteur;
    win=window.open(img,"",proprietes);
  }
}
</script>