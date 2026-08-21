// This file is released into the public domain. See COPYING.

params [];

private _fnc_getHeadTransform = {
    params [];

    private _localPosition = player selectionPosition ["head", "Memory", "AveragePoint"];
    private _localDirections = player selectionVectorDirAndUp ["head", "Memory"];
    private _localForwards = _localDirections select 0;
    private _localUpwards = _localDirections select 1;

    [
        AGLToASL (player modelToWorld _localPosition),
        player vectorModelToWorld _localForwards,
        player vectorModelToWorld _localUpwards
    ];
};

private _fnc_getCameraTransform = {
    params [];

    private _positionAGL = positionCameraToWorld [0, 0, 0];
    // Camera space is [X, Z, Y], not [X, Y, Z].
    private _forwards = positionCameraToWorld [0, 0, 1] vectorDiff _positionAGL;
    _forwards = vectorNormalized _forwards;
    private _upwards = positionCameraToWorld [0, 1, 0] vectorDiff _positionAGL;
    _upwards = vectorNormalized _upwards;

    [
        AGLToASL _positionAGL,
        _forwards,
        _upwards
    ];
};

private _headTransform = call _fnc_getHeadTransform;
private _cameraTransform = call _fnc_getCameraTransform;
private _arguments = _headTransform + _cameraTransform;
_arguments call VGR_fnc_mumbleFrameUpdate;

nil;
