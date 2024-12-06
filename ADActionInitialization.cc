#include "ADActionInitialization.hh"
#include "ADPrimaryGeneratorAction.hh"
#include "ADRunAction.hh"
#include "ADEventAction.hh"
#include "B1SteppingAction.hh"

ADActionInitialization::ADActionInitialization():G4VUserActionInitialization()
{}

ADActionInitialization::~ADActionInitialization()
{}

void ADActionInitialization::Build() const
{
	SetUserAction(new ADPrimaryGeneratorAction);

	ADRunAction* runAction = new ADRunAction;
	SetUserAction(runAction);

	ADEventAction* eventAction = new ADEventAction(runAction);
	SetUserAction(eventAction);

	SetUserAction(new B1SteppingAction(fDetConstruction, eventAction));
	
}
void ADActionInitialization::BuildForMaster() const
{
	
	ADRunAction* runAction = new ADRunAction;
	SetUserAction(runAction);

}