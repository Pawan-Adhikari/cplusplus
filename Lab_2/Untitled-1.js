        // 🎯 MSI Monitor Deal Hunter Script
        // Paste this into your browser console on the shopping page
        window.onbeforeunload = null;

        (function() {
            'use strict';
            
            // ⚙️ CONFIGURATION - Customize these settings
            const CONFIG = {
                targetPrice: 888,           // Target price in rupees
                refreshInterval: 200,      // Refresh every 5 seconds
                alertSound: true,           // Play sound when deal is found
                autoCheckout: true,        // Set to true for auto-checkout (use carefully!)
                targetTime: "00:00",        // Time when deal goes live (24hr format)
                priceSelectors: [  
                    '.current-price',
                    '.checkout-summary-noline-value',         // Common price selectors for Indian sites
                    '.price',
                    '.sale-price',
                    '.discounted-price',
                    '[data-price]',
                    '.price-current',
                    '.final-price',
                    '.offer-price'
                ],
                checkoutSelectors: [        // Common checkout button selectors
                    'div:contains("Proceed to Pay")',
                    'div:contains("Proceed")',
                    'div:contains("Pay")',
                    'div:contains("Checkout")',
                    'div:contains("Buy Now")',
                    'button[type="submit"]',
                    '.checkout-btn',
                    '.buy-now',
                    '.add-to-cart',
                    '.proceed-checkout',
                    'input[value*="checkout"]',
                    '[onclick*="checkout"]',
                    '[onclick*="pay"]'
                ]
            };
            
            // 🎨 Create floating control panel
            const createControlPanel = () => {
                const panel = document.createElement('div');
                panel.id = 'deal-hunter-panel';
                panel.innerHTML = `
                    <div style="
                        position: fixed;
                        top: 20px;
                        right: 20px;
                        z-index: 99999;
                        background: linear-gradient(135deg, #000, #330000);
                        border: 2px solid #ff0000;
                        border-radius: 10px;
                        padding: 15px;
                        color: #ff0000;
                        font-family: 'Courier New', monospace;
                        font-size: 12px;
                        box-shadow: 0 0 20px rgba(255, 0, 0, 0.3);
                        min-width: 250px;
                        backdrop-filter: blur(10px);
                    ">
                        <div style="text-align: center; margin-bottom: 10px; font-weight: bold;">
                            🎯 DEAL HUNTER ACTIVE
                        </div>
                        <div id="dh-status">⏳ Monitoring...</div>
                        <div id="dh-price">💰 Current: Detecting...</div>
                        <div id="dh-countdown">⏰ Next check: ${CONFIG.refreshInterval/1000}s</div>
                        <div id="dh-target">🎯 Target: ₹${CONFIG.targetPrice}</div>
                        <div style="margin-top: 10px;">
                            <button id="dh-stop" style="
                                background: #ff0000;
                                color: white;
                                border: none;
                                padding: 5px 10px;
                                border-radius: 5px;
                                cursor: pointer;
                                margin-right: 5px;
                            ">STOP</button>
                            <button id="dh-test" style="
                                background: #333;
                                color: #ff0000;
                                border: 1px solid #ff0000;
                                padding: 5px 10px;
                                border-radius: 5px;
                                cursor: pointer;
                            ">TEST</button>
                        </div>
                    </div>
                `;
                document.body.appendChild(panel);
                
                // Add event listeners
                document.getElementById('dh-stop').onclick = () => {
                    clearInterval(window.dealHunterInterval);
                    panel.remove();
                    console.log('🛑 Deal Hunter stopped');
                };
                
                document.getElementById('dh-test').onclick = () => {
                    triggerDealFound(CONFIG.targetPrice);
                };
            };
            
            // 🔊 Create alert sound
            const playAlertSound = () => {
                if (!CONFIG.alertSound) return;
                
                // Create multiple alert sounds for maximum attention
                const audioContext = new (window.AudioContext || window.webkitAudioContext)();
                
                // Beep sequence
                for (let i = 0; i < 5; i++) {
                    setTimeout(() => {
                        const oscillator = audioContext.createOscillator();
                        const gainNode = audioContext.createGain();
                        
                        oscillator.connect(gainNode);
                        gainNode.connect(audioContext.destination);
                        
                        oscillator.frequency.value = 800 + (i * 200);
                        oscillator.type = 'sine';
                        
                        gainNode.gain.setValueAtTime(0.3, audioContext.currentTime);
                        gainNode.gain.exponentialRampToValueAtTime(0.01, audioContext.currentTime + 0.5);
                        
                        oscillator.start(audioContext.currentTime);
                        oscillator.stop(audioContext.currentTime + 0.5);
                    }, i * 200);
                }
            };
            
            // 🎯 Extract price from page
            const getCurrentPrice = () => {
                for (const selector of CONFIG.priceSelectors) {
                    const elements = document.querySelectorAll(selector);
                    for (const element of elements) {
                        const text = element.textContent || element.innerText || element.getAttribute('data-price') || '';
                        const priceMatch = text.match(/[\d,]+/);
                        if (priceMatch) {
                            const price = parseInt(priceMatch[0].replace(/,/g, ''));
                            if (price > 100 && price < 100000) { // Reasonable price range
                                return price;
                            }
                        }
                    }
                }
                return null;
            };
            
            // 🚀 Trigger deal found actions
            const triggerDealFound = (price) => {
                console.log(`🔥 DEAL FOUND! Price: ₹${price}`);
                
                // Update panel
                document.getElementById('dh-status').innerHTML = '🔥 DEAL FOUND!';
                document.getElementById('dh-status').style.animation = 'blink 0.5s infinite';
                
                // Play alert sound
                playAlertSound();
                
                // Browser notification
                if ('Notification' in window) {
                    new Notification('🔥 MSI Monitor Deal Live!', {
                        body: `Price dropped to ₹${price}! Go checkout now!`,
                        icon: 'data:image/svg+xml,<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 100 100"><text y="50" font-size="50">🎯</text></svg>',
                        requireInteraction: true
                    });
                }
                
                // Auto-checkout if enabled
                if (CONFIG.autoCheckout) {
                    setTimeout(() => {
                        attemptCheckout();
                    }, 1000);
                }
                
                // Alert popup
                alert(`🔥 DEAL IS LIVE! MSI Monitor now ₹${price}!\n\nGO CHECKOUT NOW!`);
            };
            
            // 🛒 Attempt auto-checkout
            const attemptCheckout = () => {
                console.log('🛒 Attempting auto-checkout...');
                
            
            // First try text-based search for div elements
            const allElements = document.querySelectorAll('div, button, a, span');
            for (const element of allElements) {
                const text = (element.textContent || element.innerText || '').toLowerCase();
                if (text.includes('Proceed to pay') || text.includes('proceed') || text.includes('checkout') || text.includes('buy now')) {
                    if (element.offsetParent !== null) { // Check if visible
                        console.log(`🎯 Found checkout element: ${element.tagName} with text: ${text}`);
                        element.click();
                        setTimeout(() => {
                            // Try to find and click final checkout/buy button
                            const finalButtons = document.querySelectorAll('button, input[type="submit"], div, a');
                            for (const btn of finalButtons) {
                                const btnText = (btn.textContent || btn.value || '').toLowerCase();
                                if (btnText.includes('place order') || btnText.includes('complete') || btnText.includes('pay now') || btnText.includes('confirm')) {
                                    console.log('🚀 Clicking final checkout button');
                                    btn.click();
                                    break;
                                }
                            }
                        }, 2000);
                        return;
                    }
                }
            }
            
            // Fallback to traditional button selectors
            const buttonSelectors = ['button[type="submit"]', '.checkout-btn', '.buy-now', '.add-to-cart'];
            for (const selector of buttonSelectors) {
                const button = document.querySelector(selector);
                if (button && button.offsetParent !== null) {
                    console.log(`🎯 Found checkout button: ${selector}`);
                    button.click();
                    break;
                }
            }
            };
            
            // ⏰ Time-based actions
            const checkTimeBasedTrigger = () => {
                const now = new Date();
                const currentTime = now.getHours().toString().padStart(2, '0') + ':' + 
                                now.getMinutes().toString().padStart(2, '0');
                
                if (currentTime === CONFIG.targetTime) {
                    console.log('🕛 Target time reached! Increasing refresh rate...');
                    clearInterval(window.dealHunterInterval);
                    CONFIG.refreshInterval = 1000; // Refresh every second at target time
                    startMonitoring();
                }
            };
            
            // 📊 Main monitoring function
            const monitorPrice = () => {
                const currentPrice = getCurrentPrice();
                const now = new Date().toLocaleTimeString();
                
                // Update panel
                if (document.getElementById('dh-price')) {
                    document.getElementById('dh-price').innerHTML = 
                        currentPrice ? `💰 Current: ₹${currentPrice}` : '💰 Current: Not detected';
                }
                
                console.log(`[${now}] Price check: ₹${currentPrice || 'Not detected'}`);
                
                // Check if deal is live
                if (currentPrice && currentPrice <= CONFIG.targetPrice) {
                    triggerDealFound(currentPrice);
                    return;
                }
                
                // Check time-based trigger
                checkTimeBasedTrigger();
                
                // Random refresh timing to avoid detection
                const nextRefresh = CONFIG.refreshInterval + (Math.random() * 2000 - 1000);
                
                // Update countdown
                if (document.getElementById('dh-countdown')) {
                    let countdown = Math.ceil(nextRefresh / 1000);
                    const countdownInterval = setInterval(() => {
                        if (document.getElementById('dh-countdown')) {
                            document.getElementById('dh-countdown').innerHTML = `⏰ Next: ${countdown}s`;
                        }
                        countdown--;
                        if (countdown <= 0) clearInterval(countdownInterval);
                    }, 1000);
                }
                
                // Schedule next check
                setTimeout(() => {
                    // Add small random delay to appear more human
                    setTimeout(monitorPrice, Math.random() * 500);
                }, nextRefresh);
            };
            
            // 🚀 Start monitoring
            const startMonitoring = () => {
                console.log('🎯 MSI Monitor Deal Hunter Started!');
                console.log(`⚙️ Target Price: ₹${CONFIG.targetPrice}`);
                console.log(`⏱️ Refresh Interval: ${CONFIG.refreshInterval}ms`);
                console.log(`🛒 Auto-checkout: ${CONFIG.autoCheckout ? 'ON' : 'OFF'}`);
                
                // Request notification permission
                if ('Notification' in window && Notification.permission === 'default') {
                    Notification.requestPermission();
                }
                
                // Create control panel
                createControlPanel();
                
                // Add CSS for blink animation
                const style = document.createElement('style');
                style.textContent = `
                    @keyframes blink {
                        0%, 50% { opacity: 1; }
                        51%, 100% { opacity: 0.3; }
                    }
                `;
                document.head.appendChild(style);
                
                // Start monitoring
                monitorPrice();
            };
            
            // 🛡️ Page change detection and auto-restart
            let lastUrl = location.href;
            new MutationObserver(() => {
                const url = location.href;
                if (url !== lastUrl) {
                    lastUrl = url;
                    console.log('🔄 Page changed, restarting monitor...');
                    setTimeout(startMonitoring, 2000);
                }
            }).observe(document, {subtree: true, childList: true});
            
            // Initialize
            startMonitoring();
            
            // Global controls
            window.dealHunter = {
                stop: () => {
                    clearInterval(window.dealHunterInterval);
                    document.getElementById('deal-hunter-panel')?.remove();
                    console.log('🛑 Deal Hunter stopped');
                },
                config: CONFIG,
                testAlert: () => triggerDealFound(CONFIG.targetPrice)
            };
            
            console.log('ℹ️ Use dealHunter.stop() to stop monitoring');
            console.log('ℹ️ Use dealHunter.testAlert() to test alert system');
            
        })();

        // 🎯 USAGE INSTRUCTIONS:
        // 1. Open your shopping page with MSI monitor in cart
        // 2. Press F12 to open developer console
        // 3. Paste this entire script and press Enter
        // 4. The script will start monitoring automatically
        // 5. A red control panel will appear in top-right corner
        // 6. Script will alert you when price drops to ₹999

        console.log(`
        🎯 MSI MONITOR DEAL HUNTER SCRIPT LOADED!

        📋 QUICK SETUP:
        1. Make sure monitor is in your cart
        2. Keep this page open
        3. Script is now monitoring every 5 seconds
        4. Will alert when price drops to ₹999

        ⚙️ ADVANCED SETTINGS:
        - Edit CONFIG object at top of script to customize
        - Set autoCheckout: true for automatic checkout (risky!)
        - Adjust targetPrice if deal price changes

        🚀 GOOD LUCK WITH YOUR DEAL!
        `);