import os
import re
from sys import argv

def sort_all_arrays_in_file(filename):
    with open(filename, 'r') as file:
        content = file.read()

    array_pattern = re.compile(r'std::to_array<std::string_view>\(\{([\s\S]*?)\}\);')
    matches = array_pattern.findall(content)

    if not matches:
        print(f"No std::to_array<std::string_view> arrays found in {filename}.")
        return

    for match in matches:
        elements = re.split(r',\s*(?=")', match.strip())

        elements = [element.strip().replace(",", "") for element in elements if element.strip()]

        sorted_elements = sorted(elements, key=lambda x: x.strip('"'))

        sorted_array = ',\n    '.join(sorted_elements)
        sorted_array += ","
        sorted_array = f'std::to_array<std::string_view>({{\n    {sorted_array}\n}});'

        old_array_pattern = re.escape(f'std::to_array<std::string_view>({{{match}}});')
        content = re.sub(old_array_pattern, sorted_array, content, count=1)

    with open(filename, 'w') as file:
        file.write(content)

    print(f"Sorted arrays in {filename} successfully.")

def sort_all_arrays_in_directory(directory):
    for filename in os.listdir(directory):
        if filename.endswith('_data.h') and filename not in [
            "commerce_data.h",
            "person_data.h",
            "phone_data.h"
        ]:
            filepath = os.path.join(directory, filename)
            sort_all_arrays_in_file(filepath)

if len(argv) > 1:
    directory = argv[1]
    sort_all_arrays_in_directory(directory)
else:
    print("No directory specified, please pass in directory as command line argument")
