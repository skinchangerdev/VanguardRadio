// This file is released into the public domain. See COPYING.

params [];

private _head = ["head", "Memory"];
private _positionLocal = player selectionPosition _head;
private _directionsLocal = player selectionVectorDirAndUp _head;
private _forwardsLocal = _directionsLocal select 0;
private _upwardsLocal = _directionsLocal select 1;

private _position = player modelToWorld _positionLocal;
private _forwards = player vectorModelToWorld _forwardsLocal;
private _upwards = player vectorModelToWorld _upwardsLocal;
[_position, _forwards, _upwards] call VGR_fnc_mumbleFrameUpdate;

nil;
