// This file is released into the public domain. See COPYING.

class CfgPatches {
    class Main {
        name = "Vanguard Radio - Main";
        author = "SkinChangerDev";
        url = "";

        requiredVersion = 2.22;
        requiredAddons[] = {"CBA_main"};

        units[] = {};
        weapons[] = {};
    };
};

class CfgFunctions {
    class VGR {
        class Extension {
            file = "\z\VGR\addons\main\Extension";

            class test {};
            class mumbleInit {};
            class mumbleSessionUpdate {};
            class mumbleFrameUpdate {};
        };
    };
};
