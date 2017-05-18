/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#if TARGET_OS_IOS
#import <UIKit/UIKit.h>
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@interface FIRAppEnvironmentUtil : NSObject

/// Indicates whether the app is from Apple Store or not. Returns NO if the app is on simulator,
/// development environment or sideloaded.
+ (BOOL)isFromAppStore;

/// Indicates whether the app is a Testflight app. Returns YES if the app has sandbox receipt.
/// Returns NO otherwise.
+ (BOOL)isAppStoreReceiptSandbox;

/// Indicates whether the app is on simulator or not at runtime depending on the device
/// architecture.
+ (BOOL)isSimulator;

/// The current device model. Returns an empty string if device model cannot be retrieved.
+ (NSString *)deviceModel;

/// The current operating system version. Returns an empty string if the system version cannot be
/// retrieved.
+ (NSString *)systemVersion;

/// Indicates whether it is running inside an extension or an app.
+ (BOOL)isAppExtension;

#if TARGET_OS_IOS
/// Returns the [UIApplication sharedApplication] if it is running on an app, not an extension.
+ (nullable UIApplication *)sharedApplication;
#elif TARGET_OS_OSX
/// Returns the [NSApplication sharedApplication].
+ (NSApplication *)sharedApplication;
#endif

@end

NS_ASSUME_NONNULL_END