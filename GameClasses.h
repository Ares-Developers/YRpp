#pragma warning(disable: 4035)	//"no return value" - there is one, just not in our code ;)

#ifndef GAMECLASSES_H
#define GAMECLASSES_H

//Core
#include <YRMath.h>
#include <Randomizer.h>

//Important
#include <ArrayClasses.h>
#include <GenericList.h>
#include <GeneralStructures.h>
#include <MessageListClass.h>

#include <Unsorted.h>

//AbstractClass Tree
#include <AircraftClass.h>
#include <AirstrikeClass.h>
#include <AlphaShapeClass.h>
#include <AnimClass.h>
#include <AnimTypeClass.h>
#include <BombListClass.h>
#include <BuildingClass.h>
#include <BuildingTypeClass.h>
#include <BulletClass.h>
#include <BulletTypeClass.h>
#include <CaptureManagerClass.h>
#include <CellClass.h>
#include <DiskLaserClass.h>
#include <EMPulseClass.h>
#include <FactoryClass.h>
#include <HouseClass.h>
#include <InfantryClass.h>
#include <LightSourceClass.h>
#include <NeuronClass.h>
#include <OverlayClass.h>
#include <ParticleClass.h>
#include <ParticleSystemClass.h>
#include <RadSiteClass.h>
#include <SideClass.h>
#include <SmudgeClass.h>
#include <SuperClass.h>
#include <WarheadTypeClass.h>
#include <WeaponTypeClass.h>
#include <TacticalClass.h>
#include <TechnoClass.h>
#include <TemporalClass.h>
#include <UnitClass.h>
#include <WaypointPathClass.h>

//LocomotionClass Tree
#include <LocomotionClass.h>
#include <TeleportLocomotionClass.h>

//GScreenClass Tree
#include <SidebarClass.h>

//LinkClass Tree
#include <LinkClass.h>

//Classes without a VTable
#include <ColorScheme.h>
#include <EBolt.h>
#include <IonBlastClass.h>
#include <LaserDrawClass.h>
#include <RadarEventClass.h>
#include <Theater.h>
#include <VocClass.h>
#include <VoxClass.h>

//Static classes
#include <Ion.h>

//The law!
#include <RulesClass.h>

#endif
