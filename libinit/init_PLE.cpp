/*
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2017, The LineageOS Project

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <android-base/file.h>
#include <android-base/properties.h>

#include "init_msm8937.h"

#include "vendor_init.h"
#include "property_service.h"

using android::base::GetProperty;
using android::init::property_set;

void vendor_load_properties()
{
    std::string cmv = GetProperty("ro.boot.cmv","");

    if (cmv == "mv1")
    {
        /* TA-1021 */
        property_set("ro.sf.lcd_density", "480");
        property_set("ro.media.maxmem", "10590068224");
    }
    else if (cmv == "mv2")
    {
        /* TA-1021 */
        property_set("ro.sf.lcd_density", "480");
    }
    else if (cmv == "mv3")
    {
        /* TA-1021 */
        property_set("ro.sf.lcd_density", "480");
        property_set("persist.bootanimation.scale", "1.5");
        property_set("sys.lights.capabilities", "3");
//        property_set("ro.power_profile.override", "power_profile_2x");
    }
}

