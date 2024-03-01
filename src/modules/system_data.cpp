#include "system_data.h"

namespace faker::system::data {
const std::array<std::string_view, 3> common_interface_types = { "en", "wl", "ww" };

const std::unordered_map<std::string_view, std::string_view> common_interface_schemas
    = { { "index", "o" }, { "slot", "s" }, { "mac", "x" }, { "pci", "p" } };

const std::array<std::string_view, 7> non_standard_cron_expressions
    = { "@annually", "@daily", "@hourly", "@monthly", "@reboot", "@weekly", "@yearly" };

const std::array<std::string_view, 7> cron_day_of_week
    = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

const std::array<std::string_view, 50> directory_paths = { "/etc/mail", "/var/log", "/usr/bin",
    "/tmp", "/usr/local/lib", "/var/www/html", "/opt/app", "/home/user/documents",
    "/usr/share/fonts", "/var/cache/apt", "/etc/nginx", "/usr/local/bin", "/var/tmp", "/opt/data",
    "/home/user/pictures", "/usr/local/include", "/var/www/cgi-bin", "/etc/ssh", "/usr/local/share",
    "/var/spool/mail", "/opt/logs", "/home/user/music", "/usr/local/libexec", "/var/www/cgi-bin",
    "/etc/ssl", "/usr/local/var", "/var/spool/cron", "/opt/config", "/home/user/videos",
    "/usr/local/sbin", "/var/www/docs", "/etc/apache2", "/usr/local/games", "/var/run", "/opt/bin",
    "/home/user/downloads", "/usr/local/man", "/var/www/icons", "/etc/mysql", "/usr/local/src",
    "/var/lock", "/opt/scripts", "/home/user/public_html", "/usr/local/etc", "/var/www/logs",
    "/etc/httpd", "/usr/local/share/man", "/var/log/apache2", "/opt/files", "/home/user/backups" };

const std::array<std::string_view, 64> mime_types = { "application/atom+xml",
    "application/font-woff", "application/gzip", "application/java-archive",
    "application/javascript", "application/json", "application/ld+json", "application/msword",
    "application/octet-stream", "application/ogg", "application/pdf", "application/rdf+xml",
    "application/rtf", "application/vnd.apple.mpegurl", "application/vnd.ms-excel",
    "application/vnd.ms-fontobject",
    "application/vnd.openxmlformats-officedocument.presentationml.presentation",
    "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet",
    "application/vnd.openxmlformats-officedocument.wordprocessingml.document",
    "application/x-7z-compressed", "application/x-font-ttf", "application/x-javascript",
    "application/x-mpegURL", "application/x-rar-compressed", "application/x-shockwave-flash",
    "application/x-tar", "application/x-www-form-urlencoded", "application/xhtml+xml",
    "application/xml", "application/zip", "audio/aac", "audio/midi", "audio/ogg", "audio/wav",
    "audio/webm", "audio/mpeg", "font/woff", "font/woff2", "image/apng", "image/bmp", "image/gif",
    "image/jpeg", "image/png", "image/svg+xml", "image/tiff", "image/webp", "image/x-icon",
    "multipart/form-data", "text/calendar", "text/css", "text/csv", "text/html", "text/javascript",
    "text/plain", "text/xml", "video/mp4", "video/3gpp", "video/3gpp2", "video/mp2t", "video/mpeg",
    "video/ogg", "video/webm", "video/x-msvideo", "video/x-flv" };

// Only contains non obvious extensions.
const std::unordered_map<std::string_view, std::string_view> mime_types_extensions {
    { "application/atom+xml", "xml" }, { "application/font-woff", "woff" },
    { "application/gzip", "gz" }, { "application/java-archive", "jar" },
    { "application/javascript", "js" }, { "application/ld+json", "jsonld" },
    { "application/msword", "doc" }, { "application/octet-stream", "bin" },
    { "application/ogg", "ogx" }, { "application/vnd.ms-excel", "xls" },
    { "application/vnd.ms-fontobject", "eot" },
    { "application/vnd.openxmlformats-officedocument.presentationml.presentation", "pptx" },
    { "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", "xlsx" },
    { "application/vnd.openxmlformats-officedocument.wordprocessingml.document", "docx" },
    { "application/x-7z-compressed", "7z" }, { "application/x-tar", "tart" },
    { "application/xhtml+xml", "xhtml" },

    { "audio/ogg", "oga" }, { "audio/webm", "weba" }, { "audio/mpeg", "mp3" },

    { "image/svg+xml", "svg" },

    { "text/calendar", "ics" }, { "text/javascript", "js" }, { "text/plain", "txt" },

    { "video/3gpp", "3gp" }, { "video/3gpp2", "3g2" }, { "video/mp2t", "ts" },
    { "video/ogg", "ogv" }, { "video/x-msvideo", "avi" }
};

const std::array<std::string_view, 9> common_mime_types = { "application/pdf", "audio/mpeg",
    "audio/wav", "image/png", "image/jpeg", "image/gif", "video/mp4", "video/mpeg", "text/html" };

const std::array<std::string_view, 5> common_file_types
    = { "video", "audio", "image", "text", "application" };

}
