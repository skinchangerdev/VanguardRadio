// This file is released into the public domain. See COPYING.

params [
    ["_avatarPosition", nil, [[0]], 3],
    ["_avatarForwards", nil, [[0]], 3],
    ["_avatarUpwards", nil, [[0]], 3],
    ["_cameraPosition", nil, [[0]], 3],
    ["_cameraForwards", nil, [[0]], 3],
    ["_cameraUpwards", nil, [[0]], 3]
];

"VanguardRadio" callExtension [
    "mumbleFrameUpdate",
    [_avatarPosition, _avatarForwards, _avatarUpwards, _cameraPosition, _cameraForwards, _cameraUpwards]
];
