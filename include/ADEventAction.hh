#ifndef ADEventAction_h
#define ADEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "ADConstants.hh"
#include <array>

class ADRunAction;


class ADEventAction :public G4UserEventAction
{
public:
	ADEventAction(ADRunAction* runAction);
	virtual ~ADEventAction();

	virtual void BeginOfEventAction(const G4Event* event);
	virtual void EndOfEventAction(const G4Event* event);
	
	//event����������event��step��Ӧ��edep�����ۼ�
	void AddEdep(G4double edep , int i) { fEdep[i] += edep; }
	void AddEdepair(G4double edep) { fEdepair += edep; }

private:
	
	
	

	ADRunAction* fRunAction;
	
	//event��edep���飬��Ӧ40������ͳ������ĳ�������
	std::array<G4double,40> fEdep;
	G4double fEdepair;
	
};



#endif // !ADEventAction_h
