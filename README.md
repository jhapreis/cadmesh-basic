# CADMesh for C-Arapuca (on Geant4)

## [CadMesh](https://github.com/christopherpoole/CADMesh):

This version is prepared to run with `.obj` files.

How to use:

```
mkdir build

cd build

cmake ..

make -j4

./basic geometries/assembly/assembly1.obj
```

</br>

## [pyg4ometry](https://pypi.org/project/pyg4ometry/):

Use the `convert.py` script to convert from `.stp` files to `.gdml` files. Don't know exactly how to parse GDML to Geant4...
