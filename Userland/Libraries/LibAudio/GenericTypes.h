/*
 * Copyright (c) 2022, Lucas Chollet <lucas.chollet@free.fr>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/String.h>
#include <AK/Vector.h>

namespace Audio {

// 11.20. PICTURE_TYPE (in Flac specification)
enum class ID3PictureType : u32 {
    Other = 0,
    FileIcon = 1,
    OtherFileIcon = 2,
    FrontCover = 3,
    BackCover = 4,
    LeafletPage = 5,
    Media = 6,
    LeadArtist = 7,
    Artist = 8,
    Conductor = 9,
    Band = 10,
    Composer = 11,
    Lyricist = 12,
    RecordingLocation = 13,
    DuringRecording = 14,
    DuringPerformance = 15,
    MovieScreenCapture = 16,
    BrightColouredFish = 17,
    Illustration = 18,
    BandLogoType = 19,
    PublisherLogoType = 20,
    // others are reserved
};

// Note: This was first implemented for Flac but is compatible with ID3v2
struct PictureData {
    ID3PictureType type {};
    String mime_string {};
    Vector<u32> description_string {};

    u32 width {};
    u32 height {};
    u32 color_depth {};
    u32 colors {};

    Vector<u8> data;
};

}
