//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file B5CellParameterisation.cc
/// \brief Implementation of the B5CellParameterisation class

#include "B5CellParameterisation.hh"


#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B5CellParameterisation::B5CellParameterisation()
: G4VPVParameterisation()
{
    
  for (auto copyNo=0; copyNo<kNofEmCells; copyNo++) {
      //层数 控制y
      auto column = copyNo / kNofEmRows ;
      //当前层的第几个
    auto row = copyNo % kNofEmRows;
    //当前层的排数 控制z
    auto pai = row / 10;
    //当前排的第几个 控制x
    auto pairow = row % 10;
    /*G4cout <<"层数"<< column<<"第几个" << row<<"排数" << pai <<"当前排的第几个"
        << pairow << "*********" << G4endl;*/
    fXCell[copyNo] = pairow *5.0 *mm -22.5 * mm;
    fYCell[copyNo] = column *5.0 *mm - 22.5 * mm;
    fZCell[copyNo] = pai * 5.0 * mm - 22.5 * mm;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B5CellParameterisation::~B5CellParameterisation()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B5CellParameterisation::ComputeTransformation(
       const G4int copyNo,G4VPhysicalVolume *physVol) const
{
  physVol->SetTranslation(G4ThreeVector(fXCell[copyNo],fYCell[copyNo], fZCell[copyNo]));

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
