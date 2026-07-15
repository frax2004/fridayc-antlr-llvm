import os

# 1. Define the directories you want to scan here
DIRECTORIES_TO_SCAN = [
  "./src",
  "./include",
]


def count_lines_in_file(file_path):
  try:
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
      return sum(1 for _ in f)
  except (OSError, PermissionError) as e:
    print(f"Could not read file {file_path}: {e}")
    return 0

def count_lines_in_directories(directories):
  total_lines = 0
  file_counts = {}

  for directory in directories:
    if not os.path.exists(directory):
      print(f"Warning: Directory '{directory}' does not exist. Skipping.")
      continue

    for root, _, files in os.walk(directory):
      for file in files:
        file_path = os.path.join(root, file)

        lines = count_lines_in_file(file_path)
        if lines > 0:
          file_counts[file_path] = lines
          total_lines += lines

  return file_counts, total_lines

if __name__ == "__main__":
  files_and_counts, total = count_lines_in_directories(DIRECTORIES_TO_SCAN)

  print("\n--- Line Count per File ---")
  sorted_files = sorted(files_and_counts.items(), key=lambda x: x[1], reverse=True)
  for path, count in sorted_files:
    print(f"{path}: {count} lines")

  print("-" * 40)
  print(f"Total Lines of Code: {total}")