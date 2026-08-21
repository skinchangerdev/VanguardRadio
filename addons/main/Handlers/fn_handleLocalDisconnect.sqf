// This file is released into the public domain. See COPYING.

params [];

private _context = "";
private _identity = getPlayerUID player;
[_context, _identity] call VGR_fnc_mumbleSessionUpdate;

private _position = [0, 0, 0];
private _forwards = [1, 0, 0];
private _upwards = [0, 0, 1];
[_position, _forwards, _upwards, _position, _forwards, _upwards] call VGR_fnc_mumbleFrameUpdate;

nil;
