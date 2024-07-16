import os
import subprocess
import argparse


def format_files(directory, extensions, clang_format_path, config_path):
    formatted_files = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if any(file.endswith(ext) for ext in extensions):
                file_path = os.path.join(root, file)
                try:
                    format(clang_format_path, config_path, file_path)
                    formatted_files += 1
                except Exception as e:
                    print(
                        f"Unexpected error occurred while formatting {file_path}. Reason: {e}. Skipping..."
                    )

    print(f"\nTotal files formatted: {formatted_files}")


def format(clang_format_path, config_path, file_path):
    subprocess.run(
        [
            clang_format_path,
            "-i",
            "-style=file",
            f"-assume-filename={config_path}",
            file_path,
        ],
        check=True,
    )
    print(f"Formatted: {file_path}")


def main():
    parser = argparse.ArgumentParser(description="Format C++ files using clang-format")
    parser.add_argument("directory", help="Directory to search for files")
    parser.add_argument(
        "--clang-format", default="clang-format", help="Path to clang-format executable"
    )
    parser.add_argument(
        "--config", default=".clang-format", help="Path to .clang-format config file"
    )
    parser.add_argument(
        "--extensions",
        nargs="+",
        default=[".cpp", ".hpp", ".h", ".c"],
        help="File extensions to format",
    )

    args = parser.parse_args()

    format_files(args.directory, args.extensions, args.clang_format, args.config)


if __name__ == "__main__":
    main()
