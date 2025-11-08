pub const VOCAB: [&str; 6] = [
    "print",
    "if",
    "else",
    "for",
    "while",
    "exit",
];
pub const LA_BUFFERSIZE: usize = 16;


// list of possible tokens produced by the lexer for parsing
#[derive(Debug)]
#[derive(Clone)]
#[derive(Copy)]
pub enum TOKENS{
    _identifier,
    _num,
    
    _parentL,
    _parentR,

    _bracketL,
    _bracketR,
    
    _sbracketL,
    _sbracketR,
    
    _plus,
    _minus,
    _asterisk,
    _slash,
    _at,
    _pond,

    _quotes,
    _exclamation,
    _question,
}
impl TOKENS{
    
}

// lexer struct: contains all information needed to be able to lex and later parse programs
// program:                 the inputed program as a String
// offset:                  current location of lexer
// lookaheadBuffer          small section of program for faster indexing
// lookaheadBufferOffset:   offset needed to get from start of program to start of lookaheadBuffer
// tokenBuffer:             a list of characters consumed but not matched (due to token_step)
// tokens:                  already present tokens
#[derive(Default)]
struct Lexer{
    program: String,
    offset: usize,
    lookaheadBuffer: [char; LA_BUFFERSIZE],
    lookaheadBufferOffset: usize,
    tokenBuffer: Vec<char>,
    pub tokens: Vec<TOKENS>,
}
impl Lexer{
    // function to write program into lexer
    pub fn insert_program(&mut self, program: String) -> (){
        self.program = program.clone();
        self.lookaheadBufferOffset = 0;
        for i in 0..std::cmp::min(LA_BUFFERSIZE, program.chars().count()){
            self.lookaheadBuffer[i] = program.chars().nth(i).unwrap();
        }
    }
    // get next character
    #[inline(always)]
    fn lookahead(&mut self) -> char{
        return self.lookaheadBuffer[1];
    }
    // get nth character from current location
    #[inline(always)]
    fn lookaheadOffset(&mut self, offset: usize) -> char{
        match offset{
            0..16 => self.lookaheadBuffer[offset],
            _ => self.program.chars().nth(self.offset+offset).unwrap(),
        }
    }
    // get next character
    // holy shit I see an optimization:
    // once done, and I know the lexer doesn't care about gramar, but:
    // check a list of possible next tokens; if "IDENT" is within that list, we can just check the
    // entire next section for that ident that we already stored; if it's found, we can skip ahead
    // and also add metadata (such as striping the name in favour of something more quickly
    // indexable, such as an int; I might just cut the entire var name out if it's not used and not
    // debug flag is specified and only use the int after lexing)
    #[inline]
    pub fn tokenization_step(&mut self) -> (){      // READABLE
        match self.lookaheadBuffer[self.offset-self.lookaheadBufferOffset].is_alphabetic(){
                true => {                                                                                   // aaaaand my code is unreadable again... great
                    self.tokenBuffer.push(self.lookaheadBuffer[self.offset-self.lookaheadBufferOffset])
                }
                _ => {
                    match self.lookaheadBuffer[self.offset-self.lookaheadBufferOffset]{
                        '_' => {
                            self.tokenBuffer.push(self.lookaheadBuffer[self.offset-self.lookaheadBufferOffset]);
                        }
                        _ => {}
                    }
                }
        }
        if((self.offset+1)>=self.lookaheadBufferOffset+LA_BUFFERSIZE){                               // optimize this at some point
            for i in 0..std::cmp::min(LA_BUFFERSIZE, self.program.chars().count()-self.offset){
                self.lookaheadBuffer[i] = self.program.chars().nth(self.offset+i).unwrap();
            }
            self.lookaheadBufferOffset = self.offset+1;
        }
        self.offset += 1;
    }
}

fn main() -> (){
    for i in 0..100000{
        let mut myLexer: Lexer = Lexer::default();
        myLexer.insert_program("abcdefghijklmnopqrstuvwxyz!?,.あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん".to_string());
        for i in 0..35{
            myLexer.tokenization_step();
        }
    }
}
