class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node

    def search(self, data):
        temp = self.head
        while temp is not None:
            if temp.data == data:
                return True
            temp = temp.next
        return False


class Directory:
    def __init__(self, name):
        self.name = name
        self.subdirectories = LinkedList()

    def insert_subdirectory(self, name):
        self.subdirectories.insert(name)

    def search_subdirectory(self, name):
        return self.subdirectories.search(name)


class DirectoryStructure:
    def __init__(self):
        self.root = None
        self.hash_table = {}

    def insert_directory(self, path):
        directory_names = path.split('/')
        if self.root is None:
            self.root = Directory(directory_names[0])
            self.hash_table[directory_names[0]] = self.root
        current_directory = self.root
        for i in range(1, len(directory_names)):
            directory_name = directory_names[i]
            if directory_name not in self.hash_table:
                new_directory = Directory(directory_name)
                current_directory.insert_subdirectory(directory_name)
                self.hash_table[directory_name] = new_directory
            current_directory = self.hash_table[directory_name]

    def search_file(self, file_name):
        paths = []
        self._search_file_helper(file_name, self.root, "", paths)
        return paths

    def _search_file_helper(self, file_name, current_directory, current_path, paths):
        if current_directory is not None and current_directory.search_subdirectory(file_name):
            paths.append(current_path + '/' + current_directory.name)
        temp = current_directory.subdirectories.head
        while temp is not None:
            subdirectory_name = temp.data
            subdirectory = self.hash_table[subdirectory_name]
            self._search_file_helper(file_name, subdirectory, current_path + '/' + current_directory.name, paths)
            temp = temp.next


if __name__ == "__main__":
    directory_structure = DirectoryStructure()

    n = int(input("Enter the number of directories in the directory structure: "))
    print("Enter the directory paths (Ex. B.tech/SS): ")
    for i in range(n):
        path = input()
        directory_structure.insert_directory(path)

    file_name = input("Enter the file name to search for path: ")
    paths = directory_structure.search_file(file_name)
    if paths:
        print("File is available at:")
        for path in paths:
            print(path)
    else:
        print("File is not available.!!")
