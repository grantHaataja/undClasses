import hashlib


class Permissions(object):
    """
    rwxrwx
    |||||\ Owner exec
    ||||\ Owner write
    |||\ Owner read
    ||\ General user exec
    |\ General user write
    \ General user read
    """

    def __init__(self, perms):
        self._bits = perms
        assert len(self._bits) == 6

    def _set_bit(self, n, newval):
        bits = list(self._bits)
        bits[n] = newval
        self._bits = ''.join(bits)

    def __str__(self):
        return self._bits

    def __eq__(self, other):
        if isinstance(other, Permissions):
            return self._bits == other._bits
        elif isinstance(other, str):
            return self._bits == other
        else:
            return False

    def __hash__(self):
        return hash(self._bits)

    def __getitem__(self, bit):
        return self._bits[bit]

    def __setitem__(self, bit, newval):
        self._set_bit(bit, newval)

    @property
    def read_users(self):
        return self._bits[0] == 'r'

    @read_users.setter
    def read_users(self, allowed):
        self._set_bit(0, 'r' if allowed else '-')

    @property
    def write_users(self):
        return self._bits[1] == 'w'

    @write_users.setter
    def write_users(self, allowed):
        self._set_bit(1, 'w' if allowed else '-')

    @property
    def exec_users(self):
        return self._bits[2] == 'x'

    @exec_users.setter
    def exec_users(self, allowed):
        self._set_bit(2, 'x' if allowed else '-')

    @property
    def read_owner(self):
        return self._bits[3] == 'r'

    @read_owner.setter
    def read_owner(self, allowed):
        self._set_bit(3, 'r' if allowed else '-')

    @property
    def write_owner(self):
        return self._bits[4] == 'w'

    @write_owner.setter
    def write_owner(self, allowed):
        self._set_bit(4, 'w' if allowed else '-')

    @property
    def exec_owner(self):
        return self._bits[5] == 'x'

    @exec_owner.setter
    def exec_owner(self, allowed):
        self._set_bit(5, 'x' if allowed else '-')


class Directory(object):
    """
      Tree structure of directories and files
    """
    def __init__(self, name=None, parent=None, children=None, permissions='r-xr-x',
                 owner=None):
        self.name = name or ''
        if parent is None:
            self.parent = self
        else:
            self.parent = parent
        self.permissions = Permissions(permissions)
        self.owner = owner or 'n/a'
        self.children = {
            '.': self,
            '..': self.parent
        }
        if type(children) is dict:
            self.children.update(children)

    def mkdir(self, name, **kwargs):
        assert (name not in self.children), 'Directory already exists'
        newDir = Directory(name=name, parent=self, **kwargs)
        self.children.update({name: newDir})
        return newDir

    def addFile(self, fileName, fileContents, **kwargs):
        assert (fileName not in self.children), 'File already exists'
        assert ('.' in fileName), 'File has no type'
        newFile = File(fileName, fileContents, **kwargs)
        self.children.update({fileName: newFile})
        return newFile

    def addPrebuiltFile(self, file, **kwargs):
        assert (file.name not in self.children), "File already exists"
        self.children.update({file.name: file})
        return file

    def rmFile(self, fileName):
        assert (fileName in self.children), "File does not exist"
        assert ('.' in fileName), "File has no type"
        del self.children[fileName]

    def __iter__(self):
        return (fName for fName in self.children)

    def __repr__(self, base=True):
        output = ""
        if self.parent is not self:
            up1 = self.parent
            while isinstance(up1, Directory):
                output = up1.name + "/" + output
                if up1 is up1.parent:
                    break
                else:
                    up1 = up1.parent
        output += self.name
        if base:
            output += '/'
        return output

    __str__ = __repr__  # set __str__ as the same method as __repr__

    def __getitem__(self, item):
        assert (item in self.children), "File or Directory not found"
        return self.children[item]

    def __len__(self):
        # Remove the "." and ".." folders from the size
        # They're not really there
        return len(self.children) - 2


class File(object):
    '''
      Stores things. Like data, machine code, and blackmail
    '''
    def __init__(self, name, data='', permissions='r--r--', owner=None, **kwargs):
        self.name = name
        self._data = data
        self.permissions = Permissions(permissions)
        self.owner = owner or 'n/a'
        self._original_hash = hashlib.md5(data.encode('utf-8')).hexdigest()
        self._current_hash = hashlib.md5(data.encode('utf-8')).hexdigest()
        self._kwargs = kwargs

    def append(self, data):
        self._data += data
        self._current_hash = hashlib.md5(self._data.encode('utf-8')).hexdigest()

    @property
    def original_hash(self):
        return self._original_hash

    @property
    def current_hash(self):
        return self._current_hash

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, newdata):
        self._data = newdata
        self._current_hash = hashlib.md5(self._data.encode('utf-8')).hexdigest()

    def __repr__(self):
        return self.name
    __str__ = __repr__ # set __str__ as the same method as __repr__

    def __len__(self):
        return len(self._data)
