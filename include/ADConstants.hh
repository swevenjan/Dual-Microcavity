#ifndef ADConstants_h
#define ADConstants_h 1

#include "globals.hh"
#include "G4SystemOfUnits.hh"
//总共需要建立统计模块个数 对应step event
constexpr G4int kNofEmCel = 25;

//总共需要建立统计模块个数 对应dc
constexpr G4int kNofEmCell = 25;
//每排个数
constexpr G4int kNofEmRow = 5;

//注册栅格 1mm*1mm*1mm 共1000个

constexpr G4int layerThickness = 5 * mm;

//为小栅元的个数
constexpr G4int kNofEmCells = 1000;
//每层个数
constexpr G4int kNofEmRows = 100;

#endif
