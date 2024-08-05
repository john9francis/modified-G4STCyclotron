# Modified STCyclotron

This is a copy of the official Geant4 STCyclotron example, but modified to use any geometry.

- Todo: make a branch where instead of using inheritance, I just actually modify the main file. Aka copy it into a modified file and just adjust what I want. 
- The reason for this is to see if it's any faster. Currently, my modified STCyclotron is extremely slow compared to the original. The only difference I can think of is the inheritance may be slowing it down. It's weird that it would, but it is also just simpler in general to just modify instead of inherit. 

# Changes to original
- [ ] Removed all detectors except the target and foil (in DetectorConstruction)
- [ ] Removed constraints on the foil and target diameters (See DetectorConstruction and DetectorMessenger)
- [ ] Added functions SetTargetZ and SetFoilZ that can move around the target and foil.
- [ ] Added functions SetTargetR and SetFoilR that can adjust the size of the target and foil.

# Todo:
- [x] Get it running outside a container so I can get an OGL viewer.
- [x] Dockerize it. update: docker image can be found [here](https://hub.docker.com/repository/docker/john9francis/modified_stcyclotron)
- [x] Implement Dockerfile.dev and Dockerfile separate images. Dockerfile should take the stuff from a GitHub release using wget, and Dockerfile.dev should install git and pull from main. 
- [x] Implement a messenger to move the positions of the target and foil
- [ ] Go into where they add stuff to the 'depth' graph and subtract the position of the target, that way it starts at 0 like it should


# Acknowledgments
- This software contains official [Geant4](https://geant4.web.cern.ch/) software and should only be used according to it's license. 
