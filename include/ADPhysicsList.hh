#ifndef ADPhysicsList_h
#define ADPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"


class ADPhysicsList : public G4VModularPhysicsList
{
public:
	ADPhysicsList();
	virtual ~ADPhysicsList();
	virtual void ConstructParticle();
	virtual void SetCuts();
};


#endif
