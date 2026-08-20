// This file is released into the public domain. See COPYING.

params [["_eventName", nil, [""]], ["_didJIP", nil, [false]]];

if (hasInterface) then {
    // Initialize relavant globals if needed
    if (isNil "VGR_isMumbleInitialized") then { VGR_isMumbleInitialized = true; };

    // Initialize Mumble if needed
    if (!VGR_isMumbleInitialized) then {
        private _result = call VGR_fnc_mumbleInit;
        private _returnCode = _result select 1;
        if (_returnCode == 0) then {
            VGR_isMumbleInitialized = true;
        };
    };

    // Update session information
    private _context = serverName;
    private _identity = getPlayerUID player;
    [_context, _identity] call VGR_fnc_mumbleSessionUpdate;

    // Handle frame updates
    addMissionEventHandler ["EachFrame", VGR_fnc_handleEachFrame];

    // There is no proper client-side disconnected event, so we have to use this mess
    0 spawn {
        waitUntil { !isNull findDisplay 46 };
        findDisplay 46 displayAddEventHandler ["Unload", {
            findDisplay 46 displayRemoveEventHandler ["Unload", _thisEventHandler];
            call VGR_fnc_handleLocalDisconnect;
        }];
    };
};

nil;
