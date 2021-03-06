
#include "../CV8Resource.h"
#include "../helpers/V8Helpers.h"
#include "../helpers/V8Class.h"
#include "../helpers/V8Entity.h"
#include "../helpers/V8ResourceImpl.h"
#include "cpp-sdk/objects/IVehicle.h"

static void Constructor(const v8::FunctionCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	auto ctx = isolate->GetEnteredContext();

	V8_CHECK(info.IsConstructCall(), "Handling constructor is not a function");
	V8_CHECK(info.Length() == 1, "new Handling(...) expects 1 arg");

	V8_CHECK(info[0]->IsObject(), "vehicle must be an object");
	auto objVehicle = info[0]->ToObject(ctx).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	info.This()->SetInternalField(0, info[0]);
}

static void IsModified(const v8::FunctionCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto netVehicle = v8vehicle->GetHandle().As<alt::IVehicle>().Get();

	V8_RETURN_BOOLEAN(netVehicle->IsHandlingModified());
}

static void Reset(const v8::FunctionCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto refVehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	refVehicle->ResetHandling();
}

static void HandlingNameHashGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, (vehicle->GetHandling())->GetHandlingNameHash()));
}

static void MassGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetMass()));
}

static void MassSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "mass must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetMass((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void InitialDragCoeffGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetInitialDragCoeff()));
}

static void InitialDragCoeffSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "initialDragCoeff must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetInitialDragCoeff((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void DownforceModifierGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDownforceModifier()));
}

static void DownforceModifierSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "downforceModifier must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDownforceModifier((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void unkFloat1Getter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetunkFloat1()));
}

static void unkFloat1Setter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "unkFloat1 must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetunkFloat1((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void unkFloat2Getter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetunkFloat2()));
}

static void unkFloat2Setter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "unkFloat2 must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetunkFloat2((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void CentreOfMassOffsetGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	V8ResourceImpl *resource = V8ResourceImpl::Get(isolate->GetEnteredContext());
	V8_CHECK(resource, "invalid resource");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(resource->CreateVector3((vehicle->GetHandling()->GetCentreOfMassOffset())));
}

static void CentreOfMassOffsetSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	auto ctx = isolate->GetEnteredContext();
	V8_CHECK(val->IsObject(), "centreOfMassOffset must be a Vector3");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	v8::Local<v8::Object> pos = val.As<v8::Object>();

	v8::Local<v8::Number> x = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "x").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();
	v8::Local<v8::Number> y = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "y").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();
	v8::Local<v8::Number> z = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "z").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();

	vehicle->GetHandling()->SetCentreOfMassOffset({(float)x->Value(), (float)y->Value(), (float)z->Value()});
}

static void InertiaMultiplierGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	V8ResourceImpl *resource = V8ResourceImpl::Get(isolate->GetEnteredContext());
	V8_CHECK(resource, "invalid resource");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(resource->CreateVector3((vehicle->GetHandling()->GetInertiaMultiplier())));
}

static void InertiaMultiplierSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	auto ctx = isolate->GetEnteredContext();

	V8ResourceImpl *resource = V8ResourceImpl::Get(isolate->GetEnteredContext());
	V8_CHECK(resource, "invalid resource");

	V8_CHECK(val->IsObject(), "inertiaMultiplier must be a Vector3");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	v8::Local<v8::Object> pos = val.As<v8::Object>();

	v8::Local<v8::Number> x = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "x").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();
	v8::Local<v8::Number> y = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "y").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();
	v8::Local<v8::Number> z = pos->Get(ctx, v8::String::NewFromUtf8(isolate, "z").ToLocalChecked()).ToLocalChecked()->ToNumber(ctx).ToLocalChecked();

	vehicle->GetHandling()->SetInertiaMultiplier({(float)x->Value(), (float)y->Value(), (float)z->Value()});
}

static void PercentSubmergedGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetPercentSubmerged()));
}

static void PercentSubmergedSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "percentSubmerged must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetPercentSubmerged((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void PercentSubmergedRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetPercentSubmergedRatio()));
}

static void PercentSubmergedRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "percentSubmergedRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetPercentSubmergedRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void DriveBiasFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDriveBiasFront()));
}

static void DriveBiasFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "driveBiasFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDriveBiasFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void AccelerationGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetAcceleration()));
}

static void AccelerationSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "acceleration must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetAcceleration((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void InitialDriveGearsGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetInitialDriveGears()));
}

static void InitialDriveGearsSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "initialDriveGears must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetInitialDriveGears(val->ToUint32(isolate->GetEnteredContext()).ToLocalChecked()->Value());
}

static void DriveInertiaGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDriveInertia()));
}

static void DriveInertiaSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "driveInertia must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDriveInertia((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void ClutchChangeRateScaleUpShiftGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetClutchChangeRateScaleUpShift()));
}

static void ClutchChangeRateScaleUpShiftSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "clutchChangeRateScaleUpShift must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetClutchChangeRateScaleUpShift((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void ClutchChangeRateScaleDownShiftGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetClutchChangeRateScaleDownShift()));
}

static void ClutchChangeRateScaleDownShiftSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "clutchChangeRateScaleDownShift must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetClutchChangeRateScaleDownShift((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void InitialDriveForceGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetInitialDriveForce()));
}

static void InitialDriveForceSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "initialDriveForce must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetInitialDriveForce((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void DriveMaxFlatVelGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDriveMaxFlatVel()));
}

static void DriveMaxFlatVelSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "driveMaxFlatVel must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDriveMaxFlatVel((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void InitialDriveMaxFlatVelGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetInitialDriveMaxFlatVel()));
}

static void InitialDriveMaxFlatVelSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "initialDriveMaxFlatVel must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetInitialDriveMaxFlatVel((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void BrakeForceGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetBrakeForce()));
}

static void BrakeForceSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "brakeForce must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetBrakeForce((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void unkFloat4Getter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetunkFloat4()));
}

static void unkFloat4Setter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "unkFloat4 must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetunkFloat4((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void BrakeBiasFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetBrakeBiasFront()));
}

static void BrakeBiasFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "brakeBiasFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetBrakeBiasFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void BrakeBiasRearGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetBrakeBiasRear()));
}

static void BrakeBiasRearSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "brakeBiasRear must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetBrakeBiasRear((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void HandBrakeForceGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetHandBrakeForce()));
}

static void HandBrakeForceSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "handBrakeForce must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetHandBrakeForce((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SteeringLockGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSteeringLock()));
}

static void SteeringLockSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "steeringLock must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSteeringLock((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SteeringLockRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSteeringLockRatio()));
}

static void SteeringLockRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "steeringLockRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSteeringLockRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveMaxGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveMax()));
}

static void TractionCurveMaxSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveMax must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveMax((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveMaxRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveMaxRatio()));
}

static void TractionCurveMaxRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveMaxRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveMaxRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveMinGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveMin()));
}

static void TractionCurveMinSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveMin must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveMin((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveMinRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveMinRatio()));
}

static void TractionCurveMinRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveMinRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveMinRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveLateralGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveLateral()));
}

static void TractionCurveLateralSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveLateral must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveLateral((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionCurveLateralRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionCurveLateralRatio()));
}

static void TractionCurveLateralRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionCurveLateralRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionCurveLateralRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionSpringDeltaMaxGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionSpringDeltaMax()));
}

static void TractionSpringDeltaMaxSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionSpringDeltaMax must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionSpringDeltaMax((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionSpringDeltaMaxRatioGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionSpringDeltaMaxRatio()));
}

static void TractionSpringDeltaMaxRatioSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionSpringDeltaMaxRatio must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionSpringDeltaMaxRatio((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void LowSpeedTractionLossMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetLowSpeedTractionLossMult()));
}

static void LowSpeedTractionLossMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "lowSpeedTractionLossMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetLowSpeedTractionLossMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void CamberStiffnesssGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetCamberStiffnesss()));
}

static void CamberStiffnesssSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "camberStiffnesss must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetCamberStiffnesss((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionBiasFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionBiasFront()));
}

static void TractionBiasFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionBiasFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionBiasFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionBiasRearGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionBiasRear()));
}

static void TractionBiasRearSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionBiasRear must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionBiasRear((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void TractionLossMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetTractionLossMult()));
}

static void TractionLossMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "tractionLossMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetTractionLossMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionForceGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionForce()));
}

static void SuspensionForceSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionForce must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionForce((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionCompDampGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionCompDamp()));
}

static void SuspensionCompDampSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionCompDamp must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionCompDamp((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionReboundDampGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionReboundDamp()));
}

static void SuspensionReboundDampSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionReboundDamp must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionReboundDamp((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionUpperLimitGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionUpperLimit()));
}

static void SuspensionUpperLimitSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionUpperLimit must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionUpperLimit((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionLowerLimitGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionLowerLimit()));
}

static void SuspensionLowerLimitSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionLowerLimit must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionLowerLimit((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionRaiseGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionRaise()));
}

static void SuspensionRaiseSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionRaise must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionRaise((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionBiasFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionBiasFront()));
}

static void SuspensionBiasFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionBiasFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionBiasFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SuspensionBiasRearGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSuspensionBiasRear()));
}

static void SuspensionBiasRearSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "suspensionBiasRear must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSuspensionBiasRear((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void AntiRollBarForceGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetAntiRollBarForce()));
}

static void AntiRollBarForceSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "antiRollBarForce must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetAntiRollBarForce((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void AntiRollBarBiasFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetAntiRollBarBiasFront()));
}

static void AntiRollBarBiasFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "antiRollBarBiasFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetAntiRollBarBiasFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void AntiRollBarBiasRearGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetAntiRollBarBiasRear()));
}

static void AntiRollBarBiasRearSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "antiRollBarBiasRear must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetAntiRollBarBiasRear((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void RollCentreHeightFrontGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetRollCentreHeightFront()));
}

static void RollCentreHeightFrontSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "rollCentreHeightFront must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetRollCentreHeightFront((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void RollCentreHeightRearGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetRollCentreHeightRear()));
}

static void RollCentreHeightRearSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "rollCentreHeightRear must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetRollCentreHeightRear((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void CollisionDamageMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetCollisionDamageMult()));
}

static void CollisionDamageMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "collisionDamageMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetCollisionDamageMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void WeaponDamageMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetWeaponDamageMult()));
}

static void WeaponDamageMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "weaponDamageMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetWeaponDamageMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void DeformationDamageMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDeformationDamageMult()));
}

static void DeformationDamageMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "deformationDamageMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDeformationDamageMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void EngineDamageMultGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetEngineDamageMult()));
}

static void EngineDamageMultSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "engineDamageMult must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetEngineDamageMult((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void PetrolTankVolumeGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetPetrolTankVolume()));
}

static void PetrolTankVolumeSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "petrolTankVolume must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetPetrolTankVolume((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void OilVolumeGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetOilVolume()));
}

static void OilVolumeSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "oilVolume must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetOilVolume((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void unkFloat5Getter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetunkFloat5()));
}

static void unkFloat5Setter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "unkFloat5 must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetunkFloat5((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SeatOffsetDistXGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSeatOffsetDistX()));
}

static void SeatOffsetDistXSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "seatOffsetDistX must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSeatOffsetDistX((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SeatOffsetDistYGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSeatOffsetDistY()));
}

static void SeatOffsetDistYSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "seatOffsetDistY must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSeatOffsetDistY((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void SeatOffsetDistZGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetSeatOffsetDistZ()));
}

static void SeatOffsetDistZSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "seatOffsetDistZ must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetSeatOffsetDistZ((float)val->NumberValue(isolate->GetEnteredContext()).ToChecked());
}

static void MonetaryValueGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetMonetaryValue()));
}

static void MonetaryValueSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "monetaryValue must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetMonetaryValue(val->ToUint32(isolate->GetEnteredContext()).ToLocalChecked()->Value());
}

static void ModelFlagsGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetModelFlags()));
}

static void ModelFlagsSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "modelFlags must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetModelFlags(val->ToUint32(isolate->GetEnteredContext()).ToLocalChecked()->Value());
}

static void HandlingFlagsGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetHandlingFlags()));
}

static void HandlingFlagsSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "handlingFlags must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetHandlingFlags(val->ToUint32(isolate->GetEnteredContext()).ToLocalChecked()->Value());
}

static void DamageFlagsGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value> &info)
{
	v8::Isolate *isolate = info.GetIsolate();

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	info.GetReturnValue().Set(v8::Number::New(isolate, vehicle->GetHandling()->GetDamageFlags()));
}

static void DamageFlagsSetter(v8::Local<v8::String>, v8::Local<v8::Value> val, const v8::PropertyCallbackInfo<void> &info)
{
	v8::Isolate *isolate = info.GetIsolate();
	V8_CHECK(val->IsNumber(), "damageFlags must be a number");

	auto objVehicle = info.This()->GetInternalField(0)->ToObject(isolate->GetEnteredContext()).ToLocalChecked();

	auto v8vehicle = V8Entity::Get(objVehicle);
	V8_CHECK(v8vehicle, "entity is invalid");

	auto vehicle = v8vehicle->GetHandle().As<alt::IVehicle>();

	vehicle->GetHandling()->SetDamageFlags(val->ToUint32(isolate->GetEnteredContext()).ToLocalChecked()->Value());
}

extern V8Class v8Handling(
	"Handling", Constructor, [](v8::Local<v8::FunctionTemplate> tpl) {
		v8::Isolate *isolate = v8::Isolate::GetCurrent();

		v8::Local<v8::ObjectTemplate> proto = tpl->PrototypeTemplate();

		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		proto->Set(isolate, "isModified", v8::FunctionTemplate::New(isolate, &IsModified));
		proto->Set(isolate, "reset", v8::FunctionTemplate::New(isolate, &Reset));

		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "handlingNameHash").ToLocalChecked(), &HandlingNameHashGetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "mass").ToLocalChecked(), &MassGetter, &MassSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "initialDragCoeff").ToLocalChecked(), &InitialDragCoeffGetter, &InitialDragCoeffSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "downforceModifier").ToLocalChecked(), &DownforceModifierGetter, &DownforceModifierSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "unkFloat1").ToLocalChecked(), &unkFloat1Getter, &unkFloat1Setter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "unkFloat2").ToLocalChecked(), &unkFloat2Getter, &unkFloat2Setter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "centreOfMassOffset").ToLocalChecked(), &CentreOfMassOffsetGetter, &CentreOfMassOffsetSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "inertiaMultiplier").ToLocalChecked(), &InertiaMultiplierGetter, &InertiaMultiplierSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "percentSubmerged").ToLocalChecked(), &PercentSubmergedGetter, &PercentSubmergedSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "percentSubmergedRatio").ToLocalChecked(), &PercentSubmergedRatioGetter, &PercentSubmergedRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "driveBiasFront").ToLocalChecked(), &DriveBiasFrontGetter, &DriveBiasFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "acceleration").ToLocalChecked(), &AccelerationGetter, &AccelerationSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "initialDriveGears").ToLocalChecked(), &InitialDriveGearsGetter, &InitialDriveGearsSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "driveInertia").ToLocalChecked(), &DriveInertiaGetter, &DriveInertiaSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "clutchChangeRateScaleUpShift").ToLocalChecked(), &ClutchChangeRateScaleUpShiftGetter, &ClutchChangeRateScaleUpShiftSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "clutchChangeRateScaleDownShift").ToLocalChecked(), &ClutchChangeRateScaleDownShiftGetter, &ClutchChangeRateScaleDownShiftSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "initialDriveForce").ToLocalChecked(), &InitialDriveForceGetter, &InitialDriveForceSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "driveMaxFlatVel").ToLocalChecked(), &DriveMaxFlatVelGetter, &DriveMaxFlatVelSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "initialDriveMaxFlatVel").ToLocalChecked(), &InitialDriveMaxFlatVelGetter, &InitialDriveMaxFlatVelSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "brakeForce").ToLocalChecked(), &BrakeForceGetter, &BrakeForceSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "unkFloat4").ToLocalChecked(), &unkFloat4Getter, &unkFloat4Setter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "brakeBiasFront").ToLocalChecked(), &BrakeBiasFrontGetter, &BrakeBiasFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "brakeBiasRear").ToLocalChecked(), &BrakeBiasRearGetter, &BrakeBiasRearSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "handBrakeForce").ToLocalChecked(), &HandBrakeForceGetter, &HandBrakeForceSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "steeringLock").ToLocalChecked(), &SteeringLockGetter, &SteeringLockSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "steeringLockRatio").ToLocalChecked(), &SteeringLockRatioGetter, &SteeringLockRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveMax").ToLocalChecked(), &TractionCurveMaxGetter, &TractionCurveMaxSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveMaxRatio").ToLocalChecked(), &TractionCurveMaxRatioGetter, &TractionCurveMaxRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveMin").ToLocalChecked(), &TractionCurveMinGetter, &TractionCurveMinSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveMinRatio").ToLocalChecked(), &TractionCurveMinRatioGetter, &TractionCurveMinRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveLateral").ToLocalChecked(), &TractionCurveLateralGetter, &TractionCurveLateralSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionCurveLateralRatio").ToLocalChecked(), &TractionCurveLateralRatioGetter, &TractionCurveLateralRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionSpringDeltaMax").ToLocalChecked(), &TractionSpringDeltaMaxGetter, &TractionSpringDeltaMaxSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionSpringDeltaMaxRatio").ToLocalChecked(), &TractionSpringDeltaMaxRatioGetter, &TractionSpringDeltaMaxRatioSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "lowSpeedTractionLossMult").ToLocalChecked(), &LowSpeedTractionLossMultGetter, &LowSpeedTractionLossMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "camberStiffnesss").ToLocalChecked(), &CamberStiffnesssGetter, &CamberStiffnesssSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionBiasFront").ToLocalChecked(), &TractionBiasFrontGetter, &TractionBiasFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionBiasRear").ToLocalChecked(), &TractionBiasRearGetter, &TractionBiasRearSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "tractionLossMult").ToLocalChecked(), &TractionLossMultGetter, &TractionLossMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionForce").ToLocalChecked(), &SuspensionForceGetter, &SuspensionForceSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionCompDamp").ToLocalChecked(), &SuspensionCompDampGetter, &SuspensionCompDampSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionReboundDamp").ToLocalChecked(), &SuspensionReboundDampGetter, &SuspensionReboundDampSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionUpperLimit").ToLocalChecked(), &SuspensionUpperLimitGetter, &SuspensionUpperLimitSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionLowerLimit").ToLocalChecked(), &SuspensionLowerLimitGetter, &SuspensionLowerLimitSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionRaise").ToLocalChecked(), &SuspensionRaiseGetter, &SuspensionRaiseSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionBiasFront").ToLocalChecked(), &SuspensionBiasFrontGetter, &SuspensionBiasFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "suspensionBiasRear").ToLocalChecked(), &SuspensionBiasRearGetter, &SuspensionBiasRearSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "antiRollBarForce").ToLocalChecked(), &AntiRollBarForceGetter, &AntiRollBarForceSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "antiRollBarBiasFront").ToLocalChecked(), &AntiRollBarBiasFrontGetter, &AntiRollBarBiasFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "antiRollBarBiasRear").ToLocalChecked(), &AntiRollBarBiasRearGetter, &AntiRollBarBiasRearSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "rollCentreHeightFront").ToLocalChecked(), &RollCentreHeightFrontGetter, &RollCentreHeightFrontSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "rollCentreHeightRear").ToLocalChecked(), &RollCentreHeightRearGetter, &RollCentreHeightRearSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "collisionDamageMult").ToLocalChecked(), &CollisionDamageMultGetter, &CollisionDamageMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "weaponDamageMult").ToLocalChecked(), &WeaponDamageMultGetter, &WeaponDamageMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "deformationDamageMult").ToLocalChecked(), &DeformationDamageMultGetter, &DeformationDamageMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "engineDamageMult").ToLocalChecked(), &EngineDamageMultGetter, &EngineDamageMultSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "petrolTankVolume").ToLocalChecked(), &PetrolTankVolumeGetter, &PetrolTankVolumeSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "oilVolume").ToLocalChecked(), &OilVolumeGetter, &OilVolumeSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "unkFloat5").ToLocalChecked(), &unkFloat5Getter, &unkFloat5Setter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "seatOffsetDistX").ToLocalChecked(), &SeatOffsetDistXGetter, &SeatOffsetDistXSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "seatOffsetDistY").ToLocalChecked(), &SeatOffsetDistYGetter, &SeatOffsetDistYSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "seatOffsetDistZ").ToLocalChecked(), &SeatOffsetDistZGetter, &SeatOffsetDistZSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "monetaryValue").ToLocalChecked(), &MonetaryValueGetter, &MonetaryValueSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "modelFlags").ToLocalChecked(), &ModelFlagsGetter, &ModelFlagsSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "handlingFlags").ToLocalChecked(), &HandlingFlagsGetter, &HandlingFlagsSetter);
		proto->SetAccessor(v8::String::NewFromUtf8(isolate, "damageFlags").ToLocalChecked(), &DamageFlagsGetter, &DamageFlagsSetter);
	});