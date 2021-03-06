//
//  PrinterError.h
//  Objective-CUPS
//
//  Copyright (c) 2014 Eldon Ahrold ( https://github.com/eahrold/Objective-CUPS )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//


#import <Foundation/Foundation.h>
extern NSString* const PIDomain;

@interface PrinterError : NSError
+ (BOOL) cupsError:(NSError**)error;
+ (BOOL) charError:(const char*)message error:(NSError**)error;
+ (BOOL) errorWithCode:(int)code error:(NSError**)error;;
+ (BOOL) errorWithCode:(NSInteger)rc message:(NSString*)msg error:(NSError**)error;;

@end

enum PrinterErrorCodes {
    kPrinterErrorSuccess = 0,

    kPrinterErrorPPDNotFound = 0x1000,
    kPrinterErrorCantOpenPPD,
    kPrinterErrorCantWriteFile,

    kPrinterErrorIncompletePrinter = 0x1010,
    kPrinterErrorInvalidProtocol,
    kPrinterErrorInvalidURL,

    kPrinterErrorBadCharactersInName = 0x1020,
    kPrinterErrorNameTooLong,
    
    kPrinterErrorProblemCancelingJobs = 0x1030,
    kPrinterErrorServerNotFound,

};

enum PrintJobErrorCodes {
    kPrintJobSuccess = 0,
    kPrintJobAlreaySubmitted = 0x2000,
    kPrintJobNoFileSubmitted,
};
