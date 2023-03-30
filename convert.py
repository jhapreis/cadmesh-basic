import pyg4ometry

r = pyg4ometry.pyoce.Reader("Assembly1.stp")
r.shapeTool.Dump()

reg = pyg4ometry.convert.oce2Geant4(r.shapeTool,"Assembly2")

w = pyg4ometry.gdml.Writer()
w.addDetector(reg)
w.write('AssemblyPython.gdml')
