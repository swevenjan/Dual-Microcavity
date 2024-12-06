#include "ADEventAction.hh"
#include "ADRunAction.hh"

#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"
#include "G4AccumulableManager.hh"


#include "G4Event.hh"
#include "G4RunManager.hh"
#include "MYHistoManager.hh"

ADEventAction::ADEventAction(ADRunAction* runAction)
	:G4UserEventAction(),
	fRunAction(runAction)
{}

ADEventAction::~ADEventAction()
{}




void ADEventAction::BeginOfEventAction(const G4Event*)
{
	//ÿ��event��ʼǰ��event��Ӧ��edep������Ϊ0
	for (int i = 0; i < 40; i++)
	{
		fEdep[i] = 0;
	}
	fEdepair = 0.;
}

void ADEventAction::EndOfEventAction(const G4Event* event)
{
	//ÿ��event����ʱ�򽫶�Ӧ��event���ݸ�run�����ۼ����
	for (int i = 0; i < 40; i++) {

		fRunAction->AddEdep(fEdep[i], i);

	}
	fRunAction->AddEdeair(fEdepair);

}