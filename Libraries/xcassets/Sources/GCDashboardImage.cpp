/* Copyright 2013-present Facebook. All Rights Reserved. */

#include <xcassets/GCDashboardImage.h>
#include <xcassets/ImageSet.h>
#include <plist/Keys/Unpack.h>

using xcassets::GCDashboardImage;
using xcassets::ImageSet;

bool GCDashboardImage::
parse(plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check)
{
    if (!Asset::parse(dict, seen, false)) {
        return false;
    }

    /* No contents is allowed for groups. */
    if (dict != nullptr) {
        auto unpack = plist::Keys::Unpack("GCDashboardImage", dict, seen);

        // TODO content-reference

        if (!unpack.complete(check)) {
            fprintf(stderr, "%s", unpack.errorText().c_str());
        }
    }

    if (!loadChildren<ImageSet>(&_children)) {
        fprintf(stderr, "error: failed to load children\n");
    }

    return true;
}


