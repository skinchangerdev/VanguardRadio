// This file is released into the public domain. See COPYING.

params [["_position", nil, [[0]], 3], ["_forwards", nil, [[0]], 3], ["_upwards", nil, [[0]], 3]];

"VanguardRadio" callExtension ["mumbleFrameUpdate", [_position, _forwards, _upwards]];
