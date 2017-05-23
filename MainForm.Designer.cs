namespace SVHNClient
{
    partial class MainForm
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.canvas = new System.Windows.Forms.PictureBox();
            this.btnRecognize = new System.Windows.Forms.Button();
            this.lblResult = new System.Windows.Forms.Label();
            this.txtServerIP = new System.Windows.Forms.TextBox();
            this.btnConnect = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.lblExplainClear = new System.Windows.Forms.Label();
            this.rdoCam = new System.Windows.Forms.RadioButton();
            this.rdoDraw = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.canvas)).BeginInit();
            this.SuspendLayout();
            // 
            // canvas
            // 
            this.canvas.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.canvas.Location = new System.Drawing.Point(12, 82);
            this.canvas.Name = "canvas";
            this.canvas.Size = new System.Drawing.Size(128, 64);
            this.canvas.TabIndex = 0;
            this.canvas.TabStop = false;
            this.canvas.Paint += new System.Windows.Forms.PaintEventHandler(this.canvas_Paint);
            this.canvas.MouseClick += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseClick);
            this.canvas.MouseDown += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseDown);
            this.canvas.MouseMove += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseMove);
            this.canvas.MouseUp += new System.Windows.Forms.MouseEventHandler(this.canvas_MouseUp);
            // 
            // btnRecognize
            // 
            this.btnRecognize.Enabled = false;
            this.btnRecognize.Location = new System.Drawing.Point(280, 82);
            this.btnRecognize.Name = "btnRecognize";
            this.btnRecognize.Size = new System.Drawing.Size(92, 64);
            this.btnRecognize.TabIndex = 1;
            this.btnRecognize.Text = "Recognize";
            this.btnRecognize.UseVisualStyleBackColor = true;
            this.btnRecognize.Click += new System.EventHandler(this.btnRecognize_Click);
            // 
            // lblResult
            // 
            this.lblResult.BackColor = System.Drawing.Color.Black;
            this.lblResult.Font = new System.Drawing.Font("굴림", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lblResult.ForeColor = System.Drawing.Color.White;
            this.lblResult.Location = new System.Drawing.Point(146, 82);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(128, 64);
            this.lblResult.TabIndex = 2;
            this.lblResult.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // txtServerIP
            // 
            this.txtServerIP.Location = new System.Drawing.Point(65, 12);
            this.txtServerIP.Name = "txtServerIP";
            this.txtServerIP.Size = new System.Drawing.Size(128, 21);
            this.txtServerIP.TabIndex = 8;
            this.txtServerIP.Text = "163.152.111.74";
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(199, 12);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(76, 21);
            this.btnConnect.TabIndex = 7;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 12);
            this.label1.TabIndex = 9;
            this.label1.Text = "Server:";
            // 
            // lblExplainClear
            // 
            this.lblExplainClear.AutoSize = true;
            this.lblExplainClear.Location = new System.Drawing.Point(15, 62);
            this.lblExplainClear.Name = "lblExplainClear";
            this.lblExplainClear.Size = new System.Drawing.Size(192, 12);
            this.lblExplainClear.TabIndex = 10;
            this.lblExplainClear.Text = "Click right mouse button to clear!";
            // 
            // rdoCam
            // 
            this.rdoCam.AutoSize = true;
            this.rdoCam.Location = new System.Drawing.Point(70, 43);
            this.rdoCam.Margin = new System.Windows.Forms.Padding(1);
            this.rdoCam.Name = "rdoCam";
            this.rdoCam.Size = new System.Drawing.Size(51, 16);
            this.rdoCam.TabIndex = 11;
            this.rdoCam.TabStop = true;
            this.rdoCam.Text = "CAM";
            this.rdoCam.UseVisualStyleBackColor = true;
            this.rdoCam.CheckedChanged += new System.EventHandler(this.rdoCam_CheckedChanged);
            // 
            // rdoDraw
            // 
            this.rdoDraw.AutoSize = true;
            this.rdoDraw.Checked = true;
            this.rdoDraw.Location = new System.Drawing.Point(17, 43);
            this.rdoDraw.Margin = new System.Windows.Forms.Padding(1);
            this.rdoDraw.Name = "rdoDraw";
            this.rdoDraw.Size = new System.Drawing.Size(52, 16);
            this.rdoDraw.TabIndex = 12;
            this.rdoDraw.TabStop = true;
            this.rdoDraw.Text = "Draw";
            this.rdoDraw.UseVisualStyleBackColor = true;
            this.rdoDraw.CheckedChanged += new System.EventHandler(this.rdoDraw_CheckedChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 159);
            this.Controls.Add(this.rdoDraw);
            this.Controls.Add(this.rdoCam);
            this.Controls.Add(this.lblExplainClear);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtServerIP);
            this.Controls.Add(this.btnConnect);
            this.Controls.Add(this.lblResult);
            this.Controls.Add(this.btnRecognize);
            this.Controls.Add(this.canvas);
            this.KeyPreview = true;
            this.Name = "MainForm";
            this.Text = "SVHN Client(Sanghyun Park)";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm_KeyDown);
            ((System.ComponentModel.ISupportInitialize)(this.canvas)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox canvas;
        private System.Windows.Forms.Button btnRecognize;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.TextBox txtServerIP;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblExplainClear;
        private System.Windows.Forms.RadioButton rdoCam;
        private System.Windows.Forms.RadioButton rdoDraw;
    }
}

