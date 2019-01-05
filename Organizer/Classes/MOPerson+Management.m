//
//  MOPerson+Management.m
//  Organizer
//
//  Created by Chris Miles on 16/06/11.
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

#import "MOPerson+Management.h"

static NSString *entityName = @"Person";

@implementation MOPerson ( Management )

+ (MOPerson *)insertPersonWithUsername:(NSString *)username password:(NSString *)password name:(NSString *)name managedObjectContext:(NSManagedObjectContext *)moc
{
    MOPerson *person = (MOPerson *)[NSEntityDescription insertNewObjectForEntityForName:entityName
                                                                 inManagedObjectContext:moc];
    person.username = username;
    person.name = name;
    person.password = password;
    
    return person;
}

+ (MOPerson *)insertPersonWithUsername:(NSString *)username password:(NSString *)password name:(NSString *)name
{
    NSManagedObjectContext *moc = defaultManagedObjectContext();
    return [MOPerson insertPersonWithUsername:username password:password name:name managedObjectContext:moc];
}

+ (MOPerson *)personWithUsername:(NSString *)username password:(NSString *)password
{
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"username == %@ and password == %@", username, password];
    
    NSArray *sortDescriptors = [NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"username" ascending:YES]];
    
    MOPerson *person = (MOPerson *)fetchManagedObject(entityName, predicate, sortDescriptors, defaultManagedObjectContext());
    
    return person;
}

@end
