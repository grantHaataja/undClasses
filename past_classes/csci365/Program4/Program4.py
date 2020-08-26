#Grant Haataja
#CSCI 365 Program4
import sys


#function to split and analyze a statement
def analyze(tkl):
    stmt = tkl[0]
    tkl.pop(0)
    
    #check for <error> cases
    if stmt == '<error>':
        print('InputFileError: {} is not a valid token'.format(stmt))
        exit()
        
    #check <id> cases
    elif stmt == '<id>':
        if len(tkl) == 0:
            print('EndOfFileError: Expected token after {} but none found'.format(stmt))
            exit()
        stmt2 = tkl[0]
        tkl.pop(0)
        if stmt2 != '<assign>' and stmt2 != '<rel_op>':
            print('MissingAssignmentOrComparisonError: {} is not a valid assignment or comparison token'.format(stmt2))
            exit()
        if len(tkl) == 0:
            print('EndOfFileError: Expected token after {} but none found'.format(stmt2))
            exit()
        stmt3 = tkl[0]
        tkl.pop(0)
        if stmt3 != '<id>' and stmt3 != '<number>':
            print('InvalidAssignmentOrComparisonError: {} is not a valid id or number token'.format(stmt3))
            exit()
            
    #check <input> cases
    elif stmt == '<input>':
        if len(tkl) == 0:
            print('EndOfFileError: Expected token after {} but none found'.format(stmt))
            exit()
        stmt2 = tkl[0]
        tkl.pop(0)
        if stmt2 != '<id>':
            print('MissingIdError: {} is not a valid id token'.format(stmt2))
            exit()
    
    #check <print> cases
    elif stmt == '<print>':
        if len(tkl) == 0:
            print('EndOfFileError: Expected token after {} but none found'.format(stmt))
            exit()
        stmt2 = tkl[0]
        tkl.pop(0)
        if stmt2 != '<id>' and stmt2 != '<number>':
            print('PrintError: {} is not a valid id or number token'.format(stmt2))
            exit()
            
    #check <if> <else> cases
    elif stmt == '<if>':
        if len(tkl) == 0:
            print('EndOfFileError: Expected token after {} but none found'.format(stmt))
            exit()
        stmt2 = tkl[0]
        tkl.pop(0)
        #next must be a boolean expression
        if stmt2 != '<id>' and stmt2 != '<number>':
            print('InvalidBranchExpressionError: {} is not a valid id or number token'.format(stmt2))
            exit()
        if tkl[0] == '<rel_op>':
            tkl.pop(0)
            if len(tkl) == 0:
                print('EndOfFileError: Expected token after {} but none found'.format(stmt2))
                exit()
            stmt3 = tkl[0]
            tkl.pop(0)
            if stmt3 != '<id>' and stmt3 != '<number>':
                print('InvalidBooleanExpressionError: {} is not a valid id or number token'.format(stmt3))
                exit()
            #recursively call function to test statement
            tkl = analyze(tkl)
            #check for <else>
            if tkl[0] == '<else>':
                tkl.pop(0)
                if len(tkl) == 0:
                    print('EndOfFileError: Expected token after <else> but none found')
                    exit()
                #recursively call function to test statement
                tkl = analyze(tkl)
            else:
                return tkl
        else:
            return tkl
     
    #check <begin> <end> cases
    elif stmt == '<begin>':
        stmt2 = stmt
        while True:
            if len(tkl) == 0:
                print('EndOfFileError: Expected token after {} but none found'.format(stmt2))
                exit()
            stmt2 = tkl[0]
            if stmt2 == '<end>':
                tkl.pop(0)
                return tkl
            #recursively call function to test statement until <end> is foun
            tkl = analyze(tkl)
            
    #if no correct tokens are found, print unknown error        
    else:
        print('FatalLexicalError: Found unknown error while parsing {}'.format(stmt))
        exit()
        
    return tkl


tokenList = []
#open file from command line arguments
try:
    with open(sys.argv[1], 'r') as file:
        #build lists of tokens
        for line in file:
            line = line.strip()
            lineList = line.split(', ')
            tokenList.append(lineList[0])
except EnvironmentError:
    print('Could not find file: {}'.format(sys.argv[1]))
    exit()

#check if file is empty
if len(tokenList) == 0:
    print('EmptyFileError: File {} contains no tokens'.format(sys.argv[1]))
    exit()
    
#now begin analyzing list
while len(tokenList) > 0:
    tokenList = analyze(tokenList)

#if no errors are found in the analysis, print success
print('Scanning complete: No Errors found')