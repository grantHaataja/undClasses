import termcolor

class Directory:
  '''
    Tree structure of directories and files
  '''
  def __init__(self, name=None, parent=None, children=None):
    self.name = name or ''
    self.parent = parent or self # So root node points to itself as parent
    self.children = {
      '.':self,
      '..':self.parent
    }
    if type(children) is dict:
      self.children.update(children)

  def mkdir(self, name):
    assert (name not in self.children), 'Directory already exists'
    newDir = Directory(name, self)
    self.children.update({name:newDir})
    return newDir

  def addFile(self, fileName, fileContents):
    assert (fileName not in self.children), 'File already exists'
    assert ('.' in fileName), 'File has no type'
    newFile = File(fileName, fileContents)
    self.children.update({fileName:newFile})
    return newFile
  
  def rmFile(self, fileName):
    assert (fileName in self.children), "File does not exist"
    assert ('.' in fileName), "File has no type"
    del self.children[fileName]

  def __iter__(self):
    return (fName for fName in self.children)
    
  def __repr__(self, base=True):
    return (self.parent.__repr__(base=False) + '/' if self.parent.name else '') + self.name + ('/' if base else '')
  __str__ = __repr__ # set __str__ as the same method as __repr__
  
  def __getitem__(self, item):
    assert (item in self.children), "File or Directory not found"
    return self.children[item]

  def __len__(self):
    return len(self.children)


class File:
  '''
    Stores things. Like data, machine code, and blackmail
  '''
  def __init__(self, name, data='', permissions='rw-rw-', owner=None):
    self.name = name
    self.data = data
    self.permissions = permissions
    self.owner = owner

  def append(self, data):
    self.data += data

  def __repr__(self):
    return self.name
  __str__ = __repr__ # set __str__ as the same method as __repr__

  def __len__(self):
    return len(self.data)