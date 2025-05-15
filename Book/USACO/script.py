import os

def remove_files_with_extension(directory, extensions):
    for filename in os.listdir(directory):
        if any(filename.endswith(ext) for ext in extensions):
            filepath = os.path.join(directory, filename)
            os.remove(filepath)
            print(f"Deleted: {filepath}")

if __name__ == "__main__":
    directory = os.path.dirname(os.path.abspath(__file__))
    extensions = [".exe", ".txt","in","out"]
    remove_files_with_extension(directory, extensions)
