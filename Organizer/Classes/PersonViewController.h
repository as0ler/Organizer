//
//  LoginViewController.h
//  Organizer
//
//  Created by Chris Miles on 22/06/11.
//  Copyright 2011 Chris Miles. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//  
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>

typedef enum {
	PersonViewModeLogin = 0,
	PersonViewModeRegister = 1
} PersonViewMode;

@interface PersonViewController : UIViewController <UITextFieldDelegate> {
    PersonViewMode currentViewMode;
	UITextField *loginUsernameTextField;
    UITextField *loginPasswordTextField;
	UITextField *registerUsernameTextField;
    UITextField *registerPasswordTextField;
	UITextField *registerNameTextField;
	UIButton *loginButton;
	UIButton *registerButton;
}


@property (nonatomic, retain) IBOutlet UIView *loginContainerView;
@property (nonatomic, retain) IBOutlet UIView *registerContainerView;
@property (nonatomic, retain) IBOutlet UITextField *loginUsernameTextField;
@property (retain, nonatomic) IBOutlet UITextField *loginPasswordTextField;
@property (nonatomic, retain) IBOutlet UITextField *registerUsernameTextField;
@property (retain, nonatomic) IBOutlet UITextField *registerPasswordTextField;
@property (nonatomic, retain) IBOutlet UITextField *registerNameTextField;
@property (nonatomic, retain) IBOutlet UIButton *loginButton;
@property (nonatomic, retain) IBOutlet UIButton *registerButton;
@property (nonatomic, retain) IBOutlet UISegmentedControl *viewModeSegmentedControl;

- (IBAction)modeSegmentValueChangedAction:(UISegmentedControl *)segmentedControl;
- (IBAction)loginUsernameTextFieldEditingChanged:(id)sender;
- (IBAction)loginButtonAction:(id)sender;
- (IBAction)registerTextFieldEditingChanged:(id)sender;
- (IBAction)registerButtonAction:(id)sender;

@end
