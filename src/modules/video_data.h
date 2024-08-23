#pragma once

#include <array>
#include <string_view>

namespace faker::video
{
const auto formatNames = std::to_array<std::string_view>({"WebM",
                                                          "Matroska",
                                                          "Flash Video (FLV)",
                                                          "F4V",
                                                          "Vob",
                                                          "Ogg Video",
                                                          "Dirac",
                                                          "GIF",
                                                          "Video alternative to GIF",
                                                          "Multiple-image Network Graphics",
                                                          "AVI",
                                                          "MPEG Transport Stream",
                                                          "QuickTime File Format",
                                                          "Windows Media Video",
                                                          "Raw video format",
                                                          "RealMedia (RM)",
                                                          "RealMedia Variable Bitrate (RMVB)",
                                                          "VivoActive (VIV)",
                                                          "Advanced Systems Format (ASF)",
                                                          "AMV video format",
                                                          "MPEG-4 Part 14 (MP4)",
                                                          "MPEG-1",
                                                          "MPEG-2",
                                                          "M4V",
                                                          "SVI",
                                                          "3GPP",
                                                          "3GPP2",
                                                          "Material Exchange Format (MXF)",
                                                          "ROQ",
                                                          "Nullsoft Streaming Video (NSV)"});

const auto fileExtensions = std::to_array<std::string_view>(
    {".webm", ".mkv", ".flv",  ".vob", ".ogv", ".ogg", ".drc",  ".gif", ".gifv", ".mng", ".avi", ".MTS", ".M2TS",
     ".TS",   ".mov", ".qt",   ".wmv", ".yuv", ".rm",  ".rmvb", ".viv", ".asf",  ".amv", ".mp4", ".m4p", ".m4v",
     ".mpg",  ".mp2", ".mpeg", ".mpe", ".mpv", ".m2v", ".svi",  ".3gp", ".3g2",  ".mxf", ".roq", ".nsv"});

const auto videoCodecs = std::to_array<std::string_view>(
    {"VP8", "VP9", "AV1", "VP6", "Sorenson Spark", "H.264", "H.262/MPEG-2 Part 2", "MPEG-1 Part 2", "Theora", "Dirac",
     "H.263", "Motion JPEG", "H.265", "MPEG-4 Part 2", "MPEG-1 Part 2", "H.262", "RealVideo"});

const auto audioCodecs = std::to_array<std::string_view>({"Vorbis",
                                                          "Opus",
                                                          "MP3",
                                                          "ADPCM",
                                                          "Nellymoser",
                                                          "Speex",
                                                          "AAC",
                                                          "PCM",
                                                          "DTS",
                                                          "MPEG-1 Audio Layer II (MP2)",
                                                          "Dolby Digital (AC-3)",
                                                          "FLAC",
                                                          "AMR-NB",
                                                          "AMR-WB",
                                                          "AMR-WB+",
                                                          "HE-AAC v1",
                                                          "Enhanced aacPlus (HE-AAC v2)",
                                                          "RealAudio",
                                                          "G.723 ADPCM",
                                                          "IMA",
                                                          "Dolby AC-4",
                                                          "Sipro ACELP.net",
                                                          "Advanced Audio Coding",
                                                          "G.723 ADPCM audio",
                                                          "EVRC",
                                                          "SMV",
                                                          "VMR-WB"});

const auto resolutions =
    std::to_array<std::string_view>({"240p", "360p", "480p", "720p", "1080p", "1440p", "4K", "8k"});

const auto aspectRatios = std::to_array<std::string_view>(
    {"1:1", "4:3", "14:9", "16:10", "16:9", "1.85:1", "2.00:1", "2.40:1", "32:0", "21:9"});

const auto videoUrls = std::to_array<std::string_view>(
    {"https://youtu.be/_7ONEaabK90", "https://youtu.be/Jb4prVsXkZU", "https://youtu.be/XC1iWDz2gkk",
     "https://youtu.be/YjxgM4Wvcts", "https://youtu.be/9RGPe-rYlnQ", "https://youtu.be/a91oTLx-1No",
     "https://youtu.be/f21UCwIfgZk", "https://youtu.be/TvAuyIinmpI", "https://youtu.be/oavMtUWDBTM",
     "https://youtu.be/hMnk7lh9M3o", "https://youtu.be/tpr8oqyjKIc", "https://youtu.be/idRjqi8JC2U",
     "https://youtu.be/4-94JhLEiN0", "https://youtu.be/t7JCh7PHoDc", "https://youtu.be/AXOa66-k9MA",
     "https://youtu.be/TE4eplsFSms", "https://youtu.be/04v_v1gnyO8", "https://youtu.be/pIsae6YdRjw",
     "https://youtu.be/NHE7migQN7U", "https://youtu.be/FJ3oHpup-pk", "https://youtu.be/6JFVKnrE_d8"});

}