# Liste des machines sur le réseau
Il faut `git clone https://github.com/picazenave/eirb_tool.git` puis :
- **Se mettre sur une machine** (`ssh travail64` ou autre)
- Créer un dossier de build : `mkdir build` & `cd build`
- Build : `cmake ..` & `make`
- **Changer pour la machine ssh normale** (`exit` pour revenir sur la ssh normale)
- Lancer : `./main` depuis le dossier build
- Enjoy

