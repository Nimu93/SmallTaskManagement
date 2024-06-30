
# Small Task Management

Ce programme C++ liste tous les processus en cours d'exécution sur votre machine.

## Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés sur votre machine :

- Un compilateur C++ (comme g++)
- La bibliothèque TlHelp32 sur Windows
## Installation

Clonez ce dépôt sur votre machine locale :

```bash
git clone https://github.com/Nimu93/SmallTaskManagement.git
cd SmallTaskManagement
```
## Compilation

Utilisez MSBuild pour compiler le projet :

```bash
msbuild SmallTaskManagement.sln /p:Configuration=Release
```

Pour exécuter le programme, utilisez la commande suivante :

```bash
./SmallTaskManagement
```

Cela affichera une liste de tous les processus en cours d'exécution avec leurs informations détaillées, telles que l'identifiant du processus (PID) et le nom du processus.

Exemple de sortie
```bash
Process ID: 0, Name: [System Process], Thread Count: 24, Parent Process ID: 0
Process ID: 4, Name: System, Thread Count: 379, Parent Process ID: 0
...
```
Auteur

    GIBBE Valentin

Licence

Ce projet est sous licence MIT
