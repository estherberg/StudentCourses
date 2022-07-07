# StudentCourses

INTRODUCTION

WINDOWS :
Pour lancer le projet vous devez suivre le tuto ci dessous pour installer le compilateur G++ :

https://code.visualstudio.com/docs/cpp/config-mingw

et a l'etape 4 suivre les instructions pour installer mingw : https://www.msys2.org/

Pour compiler le projet vous avez besoin des lignes de commandes suivante dans un terminal sur visual studio code: Attention veillez a bien vous trouvez dans l'arboresence du dossier StudentCourses :

1 ) g++ *.cpp -o test

2 )./test

MAC : Suivre ce tutoriel :
https://code.visualstudio.com/docs/cpp/config-clang-mac

CONTENU DU PROGRAMME :

Dans cet exercice, vous devez accéder au hasard à un fichier binaire. Le programme initialise un fichier binaire pour 100 enregistrements de même taille, chacun ayant une clé principale unique numérotée de 1 à 100, selon son emplacement dans le fichier. Initialement, les enregistrements sont vides, et pendant le programme, un accès direct est fait à l'enregistrement, tel que requis par le système puisque les enregistrements sont de la même taille, il est possible de connaître l'emplacement de chaque enregistrement dans le fichier, compte tenu de sa clé principale.
